#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

template<class T> inline bool chmin(T &a, T b){
	if(a > b){a = b; return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a < b){a = b; return true;}
	return false;
}

int main()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    sort(rall(a));
    sort(rall(b));
    int ma = a[0];
    int ans = INF;
    rep(k, n + 1) {
        if(k > 0) {
            h -= b[k-1];
        }
        int cnt = 0;
        if(h > 0) {
            cnt = (h + ma - 1) / ma;
        }
        ans = min(ans, k + cnt);
    }
    cout << ans << endl;
    return 0;
}
