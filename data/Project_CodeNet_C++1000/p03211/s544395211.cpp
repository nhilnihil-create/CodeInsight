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
    string s;
    cin >> s;
    int best = 1e8;
    rep(i, s.size() - 2) {
        int x = atoi(s.substr(i, 3).c_str());
        if (best > abs(x - 753)) {
            best = abs(x - 753);
        }
    }
    put(best)
    return 0;
}