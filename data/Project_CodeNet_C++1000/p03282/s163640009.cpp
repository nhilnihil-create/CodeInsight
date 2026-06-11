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
    string s;
    cin >> s;

    ll k;
    cin >> k;

    rep(i, min((ll)s.size(), k)) {
        if (s[i] != '1') {
            put(s[i]);
            return 0;
        }
    }
    put(1);

    return 0;
}