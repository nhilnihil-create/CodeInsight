// Why I am so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int mod = (int)1e9 + 7;
const int mod1 = (int)1e9 + 9;                                                                  

vector<pair<int, int>> vv[20];

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

pair<int, int> h(string s) {
    pair<int, int> ret = mp(0, 0);

    for (int i = 0; i < s.size(); ++i) {
        int cur = s[i] - 'a' + 1;
        ret.fi = (ret.fi * 29ll + cur) % mod;
        ret.se = (ret.se * 31ll + cur) % mod1;
    }

    return ret;
}

void solve() {                   
    scanf("%d %s", &n, s);
    string sc, tc;
                  
    for (int m = 0; m < pw[n]; ++m) {
        sc.clear();
        tc.clear();

        for (int i = 0; i < n; ++i) {
            if (bit(m, i)) {
                sc.pb(s[i + n]);                
            }
            else {
                tc.pb(s[i + n]);
            }
        }

        reverse(all(tc));
        vv[sc.size()].pb(h(tc + sc));          
    }

    for (int i = 0; i < 20; ++i) {
        sort(all(vv[i]));
    }

    for (int m = 0; m < pw[n]; ++m) {
        sc.clear();
        tc.clear();

        for (int i = 0; i < n; ++i) {
            if (bit(m, i)) {
                sc.pb(s[i]);
            }
            else {
                tc.pb(s[i]);
            }
        }
        
        reverse(all(tc));
        auto it = equal_range(all(vv[tc.size()]), h(sc + tc));
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