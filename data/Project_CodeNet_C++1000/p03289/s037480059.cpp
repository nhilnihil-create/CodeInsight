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
    int cnt = 0;
    int lcnt = 0;
    rep(i, s.size()) {
        if (i == 0 && s[i] != 'A') {
            put("WA");
            return 0;
        }
        if (2 <= i && i <= s.size() - 2) {
            if (s[i] == 'C') cnt ++;
        }
        if ('a' <= s[i] && s[i] <= 'z') {
            lcnt ++;
        }
    }

    if (lcnt == s.size() - 2 && cnt == 1) {
        put("AC");
        return 0;
    }

    put("WA");

    return 0;
}