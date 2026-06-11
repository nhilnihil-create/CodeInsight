#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    string S;
    cin >> S;

    ll res = 1e18;
    rep(i, S.size()) {
        if (S[i] != S[i + 1]) {
            res = min(res, max(i+1, (ll)S.size() - i - 1));
        }
    }
    put(res);    
}
signed main(){ Main();return 0;}