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

    int best = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        int x = 0;
        for (int j = i; j < (int)s.size(); j++) {
            if (s[j] == 'A' || s[j] == 'T' || s[j] == 'C' || s[j] == 'G') {
                x += 1;
            }
            else {
                break;
            }
        }
        if (x > best) {
            best = x;
        }
    }

    put(best)

    return 0;
}