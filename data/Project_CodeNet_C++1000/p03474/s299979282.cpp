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
    int a, b;
    string s;
    cin >> a >> b >> s;
    rep(i, a) {
        if ('0' <= s[i] && s[i] <= '9') {}
        else {
            put("No");
            return 0;
        }
    }

    if (s[a] != '-') {
        put("No");
        return 0;
    }

    rep(i, b) {
        if ('0' <= s[a + 1 + i] && s[a + 1 + i] <= '9') {}
        else {
            put("No");
            return 0;
        }
    }
    put("Yes");
    return 0;
}