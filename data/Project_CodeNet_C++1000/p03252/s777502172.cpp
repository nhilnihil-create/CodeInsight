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

    vector<int> si(s.size());
    unordered_map<char, int> sm;
    rep(i, s.size()) {
        if (sm.find(s[i]) == sm.end()) {
            sm[s[i]] = i;
        }
        si[i] = sm[s[i]];
    }

    vector<int> ti(s.size());
    unordered_map<char, int> tm;
    rep(i, t.size()) {
        if (tm.find(t[i]) == tm.end()) {
            tm[t[i]] = i;
        }
        ti[i] = tm[t[i]];
    }

    rep(i, s.size()) {
        if (si[i] != ti[i]) {
            put("No");
            return 0;
        }
    }
    put("Yes")

    return 0;
}