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
    vector<string> w(n);
    rep(i, n) cin >> w[i];
    
    unordered_set<string> us;
    rep(i, n) {
        if (us.count(w[i]) >= 1) {
            put("No");
            return 0;
        }
        if (i >= 1 && w[i-1][w[i-1].size() - 1] != w[i][0]) {
            put("No");
            return 0;
        }
        us.emplace(w[i]);
    }
            put("Yes");

    return 0;
}