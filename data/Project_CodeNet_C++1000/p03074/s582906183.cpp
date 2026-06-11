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
    ll n, K;
    cin >> n >> K;

    string S;
    cin >> S;

    bool has0 = false;
    rep(i, n) {
        if (S[i] == '0') {
            has0 = true;
            break;
        }
    }

    if(!has0) {
        put(S.size());
        return;
    }

    typedef pair<ll, ll> P;
    vector<P> C;
    C.push_back(P(0, 1));
    C.push_back(P(1, S[0] - '0'));
    repi(i, n) {
        if (S[i] != S[i - 1]) {
            C.push_back(P(1, S[i] - '0'));
        }
        else {
            C[C.size()-1].first++;
        }
    }
    C.push_back(P(0, 1));

    vector<ll> Sc(C.size());
    Sc[0] = C[0].first;
    repi(i, Sc.size()) {
        Sc[i] = Sc[i-1] + C[i].first;
    }

    ll res = 0;
    rep(i, C.size()) {
        if (C[i].second == 0) {
            // i-1 ~ (i + 2K)
            ll i1 = max(0LL, i - 2);
            ll i2 = min((ll)C.size() - 1, i + 2 * K - 1);
            ll num = Sc[i2] - Sc[i1]; 
            res = max(res, num);
        }
    }

    put(res);
}
signed main(){ Main();return 0;}