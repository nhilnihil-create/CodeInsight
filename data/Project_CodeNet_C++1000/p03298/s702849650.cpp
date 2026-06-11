// Why I am so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)3e5 + 5;                                           
                         
vector<string> vv[20];

string s1[MAXN], t1[MAXN];

string s2[MAXN], t2[MAXN];

char s[55];

int pw[20];

ll ans;

int n;

void pre() {
    pw[0] = 1;

    for (int i = 1; i < 20; ++i) {
        pw[i] = (pw[i - 1] << 1);
    }
}

bool bit(int x, int p) {
    return x & pw[p];
}

void solve() {                   
    scanf("%d %s", &n, s);

    for (int m = 0; m < pw[n]; ++m) {
        for (int i = 0; i < n; ++i) {
            if (bit(m, i)) {
                s1[m].pb(s[i]);
                s2[m].pb(s[i + n]);
            }
            else {
                t1[m].pb(s[i]);
                t2[m].pb(s[i + n]);
            }
        }

        reverse(all(t1[m]));
        reverse(all(t2[m]));
    }    

    for (int m = 0; m < pw[n]; ++m) {
        vv[s2[m].size()].pb(t2[m] + s2[m]);          
    }

    for (int i = 0; i < 20; ++i) {
        sort(all(vv[i]));
    }

    for (int m = 0; m < pw[n]; ++m) {
        auto it = equal_range(all(vv[t1[m].size()]), s1[m] + t1[m]);
        ans += (it.se - it.fi);        
    }    
         
    printf("%lld\n", ans);
}

int main() {    
    int tt = 1;

    pre();

    while (tt--) {
        solve();
    }

    return 0;
}