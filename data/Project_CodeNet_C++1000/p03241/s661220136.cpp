#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i) res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(all(res));
    return res;
}

int main() {
    ll a, b,ans=0;
    cin >> a >> b;
    vector<ll>divi = enum_divisors(b);
    for (auto c : divi) {
        if (c <= b / a)ans = max(ans, c);
    }
    cout << ans << endl;
	return 0;
}

