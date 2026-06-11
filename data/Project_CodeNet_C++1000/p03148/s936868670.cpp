#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

typedef pair<ll, ll> P; // おいしさ、種類

int main() {
    ll N, K;
    cin >> N >> K;
    vector<P> sushi(N);
    rep(i, N) {
        P p;
        cin >> p.second >> p.first;
        sushi[i] = p;
    }

    sort(sushi.rbegin(), sushi.rend()); // おいしさの順にソート

    // まずはおいしさの順番に貪欲に食べていく
    ll sum = 0;
    set<ll> kinds; // 食べた寿司の種類
    priority_queue<ll, vector<ll>, greater<>> minQ; // 既に食べた種類（２番目以降の）のおいしさ
    rep(i, K) {
        P s = sushi[i];
        if (kinds.find(s.second) == kinds.end()) { // 初めて食べた種類の寿司の場合
            kinds.insert(s.second);
        } else {
            minQ.push(s.first);
        }
        sum += s.first;
    }

    ll ans = sum + pow((ll) kinds.size(), 2); // おいしさの順番に貪欲に食べた場合のまんぞくポイント

    map<ll, ll> typeToDelicious; // まだ食べていない種類 => おいしさの最大値
    for (int i = N - 1; i >= K; i--) { // 貪欲に選ばれなかった寿司をおいしさの低い順に見ていく
        P s = sushi[i];
        if (kinds.find(s.second) == kinds.end()) typeToDelicious[s.second] = s.first; // 食べていない場合はおいしさを記録する
    }

    priority_queue<ll> maxQ; // まだ食べていない種類でおいしさが最大の寿司
    for (auto x: typeToDelicious) maxQ.push(x.second);

    // minQとmaxQの寿司を入れ替えて,まんぞくポイントが増えるか試す
    ll typeCount = 0;
    while (minQ.size() && maxQ.size()) {
        sum -= minQ.top();
        minQ.pop();
        sum += maxQ.top();
        maxQ.pop();
        typeCount++;
        chmax(ans, (ll) (sum + pow((ll) kinds.size() + typeCount, 2)));
    }

    cout << ans << endl;
}
