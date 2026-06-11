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
signed main()
{
    ll n;
    cin >> n;

    if (n == 0) {
        put('0');
    }

    string s = "";
    ll r = 1;
    while (n != 0) {
        s.push_back('0' + (n % abs(r * 2) == 0 ? 0 : 1));
        n -= r * (n % abs(r * 2) == 0 ? 0 : 1);
        r *= -2;
    }

    reverse(all(s));
    put(s);

    return 0;
}