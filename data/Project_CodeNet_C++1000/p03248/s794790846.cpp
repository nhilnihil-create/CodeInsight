#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define pll pair<ll, ll>
#define pii pair<int, int>
#define f first
#define se second
#define pb push_back
 
 
using namespace std;
 
 
const int N =  2e5 + 123;
const int MAXN = 2e5;
const int brd = 32;
const ull inf = 1e18 + 7;
 
 
int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == '0' || s[n - 1] == '1')
        return cout << -1, 0;
    s = "0" + s;
    for (int i = 0; i <= n; i++) {
        if (s[i] != s[n - i])
            return cout << -1, 0;
    }
    vector <int> c, a;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1')
            c.pb(i);
    }
    c.pb(n);
    for (int i = c.size() - 1; i >= 0; i--) {
        if (i == 0)
            a.pb(c[i]);
        else
            a.pb(c[i] - c[i - 1]);
    }
    reverse(a.begin(), a.end());
    int cur = 1;
    vector <pair<int, int> > edg;
    for (int i = 0; i < a.size(); i++) {
        int root = cur;
        for (int j = 1; j <= a[i]; j++) {
            if (cur + j <= n)
                edg.pb({cur + j, root});
        }
        cur += a[i];
    }
    for (int i = 0; i < edg.size(); i++)
        cout << edg[i].f << " " << edg[i].se << endl;
}
