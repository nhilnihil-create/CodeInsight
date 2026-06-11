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
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;

    vector<ll> A(X);
    rep(i, X) cin >> A[i];
    vector<ll> B(Y);
    rep(i, Y) cin >> B[i];
    vector<ll> C(Z);
    rep(i, Z) cin >> C[i];


    vector<ll> AB;
    rep(i, X) rep(j, Y) AB.push_back(A[i] + B[j]);

    sort(all(AB));
    reverse(all(AB));

    vector<ll> ABC;
    rep(i, min((ll)AB.size(), K)) {
        rep (j, Z) {
            ABC.push_back(AB[i] + C[j]);
        }
    }
    
    sort(all(ABC));
    reverse(all(ABC));    

    rep(i, K) {
        put(ABC[i]);
    }
    
}
signed main(){ Main();return 0;}