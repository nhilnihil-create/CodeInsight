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
    ll n, m;
    cin >> n >> m;

    if (n == 1 && m == 1) {
        put(1);
        return 0;
    }

    if (n == 1) {
        put(max(0LL, m - 2));
        return 0;
    }

    if (m == 1) {
        put(max(0LL, n - 2));
        return 0;
    }

    put((m - 2) * (n - 2));

    return 0;
}