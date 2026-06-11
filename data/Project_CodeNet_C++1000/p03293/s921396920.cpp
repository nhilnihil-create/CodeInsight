#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    rep(i, s.size()) {
        string z = s.substr(i) + s.substr(0, i);
        if (t == z) {
            put("Yes");
            return 0;
        }
    }
    put("No")
    return 0;
}