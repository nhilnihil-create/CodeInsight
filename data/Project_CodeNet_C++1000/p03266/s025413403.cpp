#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    vector<ll> num(k, 0);
    for (int i = 1; i <= n; i++) num[i % k]++;
    ll res = 0;
    for (int a = 0; a < k; a++) {
        int b = (k - a) % k;
        int c = (k - a) % k;
        if ((b + c) % k != 0) continue;
        res += num[a] * num[b] * num[c];
    }
    cout << res << endl;

    return 0;
}