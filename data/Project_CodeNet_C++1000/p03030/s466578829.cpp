#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> p(n);
    rep(i, n) cin >> s[i] >> p[i];

    vector<int> v(n);
    rep(i, n) v[i] = i;
    sort(all(v), [s, p](auto const& lhs, auto const& rhs) {
        if (s[lhs] == s[rhs]) {
            return p[lhs] > p[rhs];
        }
        return s[lhs] < s[rhs];
    });

    rep(i, n) cout << 1 + v[i] << endl;
    
    return 0;
}