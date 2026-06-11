#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<vector<int>> sushi(N);
    rep(i, N) {
        int t, d;
        cin >> t >> d;
        t--;
        sushi[t].push_back(d); // おいしさを種類ごとにまとめる
    }

    vector<int> y0, y1; // y0:種類ごとでおいしさが２番目以降のもの、y1:種類ごとでおいしさが１番のもの
    rep(i, N) { // i:寿司の種類
        if (sushi[i].size() == 0) continue;
        sort(sushi[i].begin(), sushi[i].end());
        y1.push_back(sushi[i].back()); // 種類の中で最大のおいしさのもの
        sushi[i].pop_back();
        y0.insert(y0.end(), sushi[i].begin(), sushi[i].end()); // 種類の中で２番目以降のおいしさのものをy0にいれる
    }

    sort(y0.rbegin(), y0.rend());
    sort(y1.rbegin(), y1.rend());

    ll ans = 0;
    // 取り出す種類数を試す
    ll Y = max(0LL, K - (ll) (y0.size())); // 取り出す種類数の初期値
    ll X = 0; // おいしさの総和
    rep(i, Y) X += y1[i];
    rep(i, K - Y) X += y0[i];
    while (1) {
        chmax(ans, X + Y * Y);
        if (Y >= K || Y >= y1.size()) break;
        X += y1[Y];
        X -= y0[K - Y - 1];
        ++Y;
    }
    cout << ans << endl;
}
