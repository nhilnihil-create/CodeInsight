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
    ll A, B;
    cin >> A >> B;

    ll v = 0;
    if (A % 2 == 0 && B % 2 == 0){
        ll one = (B-A)/2;
        v = B ^ (one % 2 == 1 ? 1 : 0);
    }
    else if (A % 2 == 1 && B % 2 == 0){
        ll one = (B-A-1)/2;
        v = A ^ B ^ (one % 2 == 1 ? 1 : 0);
    }
    else if (A % 2 == 0 && B % 2 == 1){
        ll one = (B-A + 1)/2;
        v = one % 2 == 1 ? 1 : 0;
    }
    else if (A % 2 == 1 && B % 2 == 1){
        ll one = (B-A)/2;
        v = A ^ (one % 2 == 1 ? 1 : 0);
    }
    put(v);
}
signed main(){ Main();return 0;}