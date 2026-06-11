#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> C(n-1), S(n-1), F(n-1);
    rep(i, n-1) cin >> C[i] >> S[i] >> F[i];

    rep(s, n-1) {
        int t = S[s];
        for (int i = s; i < n - 1; i++) {
            t = S[i] + max(0, (t - S[i] + F[i] - 1) / F[i] * F[i]);
            t = t + C[i];
        }
        put(t);
    }

    put(0);

    return 0;
}