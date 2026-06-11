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
    int N;
    cin >> N;
    vector<ll> X(N);
    rep(i, N) cin >> X[i];

    vector<ll> Y = X;
    sort(all(Y));

    rep (i, N) {
        int lb = lower_bound(all(Y), X[i]) - Y.begin();
        int ub = upper_bound(all(Y), X[i]) - Y.begin();

        // [lb, ub) がX[i]
        int mid = Y.size() / 2;
        ll v = 0;
        if (ub - 1 < mid) {
            v = Y[mid];
        }
        else {
            v = Y[mid - 1];
        }

        put(v);
    }

    return 0;
}