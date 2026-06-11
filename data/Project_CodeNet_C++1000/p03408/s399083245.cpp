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
    rep(i, n) cin >> s[i];
    int m;
    cin >> m;
    vector<string> t(m);
    rep(i, m) cin >> t[i];

    int best = 0;
    rep(i, s.size()) {
        int v = 0;
        rep(j, s.size()) if (s[j] == s[i]) v++;
        rep(j, t.size()) if (t[j] == s[i]) v--;
        best = max(best, v);
    }
    
    put(best);

    return 0;
}