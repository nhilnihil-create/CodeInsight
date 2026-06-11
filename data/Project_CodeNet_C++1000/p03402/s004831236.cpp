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

    ll N = 100;
    vector<string> S(N);

    rep(i, N/2) S[i] = string(N, '#');
    rep(i, N/2) S[N/2 + i] = string(N, '.');

    rep(i, A - 1) {
        ll x = (2 * i) % N;
        ll y = ((2 * i) / N) * 2;
        S[y][x] = '.';
    }

    rep(i, B - 1) {
        ll x = (2 * i) % N;
        ll y = (N - 1) - ((2 * i) / N) * 2;
        S[y][x] = '#';
    }

    cout << N << " " << N << endl;
    rep(i, S.size()) put(S[i]);
}
signed main(){ Main();return 0;}