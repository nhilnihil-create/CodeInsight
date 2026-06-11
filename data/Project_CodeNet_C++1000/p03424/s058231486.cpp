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
    vector<char> s(n);
    rep(i, n) cin >> s[i];
    sort(all(s));
    s.erase(unique(all(s)), s.end());
    if (s.size() == 3) {
        put("Three");
    }
    else {
        put("Four");
    }
    
    return 0;
}