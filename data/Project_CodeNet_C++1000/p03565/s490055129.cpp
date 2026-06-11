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
    string s, t;
    cin >> s >> t;

    string res = s;
    bool found = false;

    rep(i, s.size() - t.size() + 1) {
        bool ok = true;
        rep (j, t.size()) {
            if ('?' != s[i + j] && s[i+j] != t[j]) {
                ok = false;
                break;
            }
        }

        if (ok) { 
            string S = s;
            rep (j, t.size()) {
                S[i + j] = t[j];
            }
            rep (j, S.size()) {
                if (S[j] == '?') S[j] = 'a';
            }
            if (!found || S < res) {
                res = S;
                found = true;
            }
        }
    }

    if (found) {put(res)}
    else {put("UNRESTORABLE")}
    

    return 0;
}