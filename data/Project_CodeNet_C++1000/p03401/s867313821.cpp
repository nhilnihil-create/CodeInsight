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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> E(N + 2);
    E.push_back(0);
    rep(i, N) E[i + 1] = A[i];
    E.push_back(0);

    vector<int> diff(N + 1);
    rep (i, N) {
        int x = abs(E[i + 1] - E[i]) + abs(E[i + 2] - E[i + 1]);
        int y = abs(E[i + 2] - E[i]);
        diff[i + 1] =  y - x;
    }

    int base = 0;
    rep (i, N + 1) {
        base += abs(E[i + 1] - E[i]);
    }

    rep (i, N) {
        put(base + diff[i + 1]);
    }

    return 0;
}