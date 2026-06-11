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
    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];

    ll ans = 0;
    rep(A, 0, N)
    {
        int B = 0;
        bool ok = true;
        rep(i, 0, N) rep(j, 0, i)
        {
            if (S[(i + A) % N][(j + B) % N] != S[(j + A) % N][(i + B) % N])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ++ans;
        }
    }
    cout << ans * N << endl;
}
