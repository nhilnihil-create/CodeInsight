#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void _main()
{
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];
    int res = 0;
    rrep(digit, 29, 0)
    {
        int bekihigh = 1 << (digit + 1), bekilow = 1 << digit;
        rep(i, 0, N) a[i] %= bekihigh, b[i] %= bekihigh;
        sort(b.begin(), b.end());
        ll num = 0;
        rep(i, 0, N)
        {
            int add = 0;
            if (bekilow - a[i] >= 0)
            {
                add += lower_bound(b.begin(), b.end(), bekihigh - a[i])
                - lower_bound(b.begin(), b.end(), bekilow - a[i]);
            }
            else
            {
                add += lower_bound(b.begin(), b.end(), bekihigh - a[i]) - b.begin();
                add += lower_bound(b.begin(), b.end(), bekihigh)
                - lower_bound(b.begin(), b.end(), bekihigh + bekilow - a[i]);
            }
            num += add;
        }
        if (num & 1) res += bekilow;
    }
    cout << res << endl;
}
