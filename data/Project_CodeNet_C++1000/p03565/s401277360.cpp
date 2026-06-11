#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

bool equal(char a, char b) {
    if (a=='?' || b=='?') return true;
    return a==b;
}

int main(){
    string s, t;
    cin >> s >> t;
    int ns = s.size();
    int nt = t.size();
    string x = "UNRESTORABLE";
    if (nt>ns) {
        cout << x << endl;
        return 0;
    }
    bool ok = false;
    int l = -1;
    for (int i=ns-nt; i>=0; i--) {
        bool z = true;
        rep(j, nt) {
            if (!equal(t[j], s[i+j])) z = false;
        }
        ok = z;
        if (ok) {
            l = i;
            break;
        }
    }
    if (!ok) {
        cout << x << endl;
        return 0;
    }
    string ans = "";
    rep(i, ns) {
        if (i>=l && i<l+nt) {
            ans += t[i-l];
        }
        else {
            if (s[i]=='?') ans += 'a';
            else ans += s[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}
