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

map<string, int> cnt[20];

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
        ++cnt[s2[m].size()][t2[m] + s2[m]];        
    }

    for (int m1 = 0; m1 < pw[n]; ++m1) {
        string P = s1[m1] + t1[m1];
        ans += cnt[t1[m1].size()][P];        
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