#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    string s;
    cin >> s;
    string t = "";
    rep(i, s.size()) {
        if(s[i] != 'x') t += s[i];
    }
    bool ok = true;
    rep(i, t.size()) {
        if(t[i] != t[t.size() - 1 - i]) ok = false;
    }
    int ans = 0;
    if(!ok) {
        cout << -1 << endl;
    }else {
        int i = 0, j = s.size() - 1, xcount_l = 0, xcount_r = 0;
        while(i < j) {
            if(s[i] == 'x') ++xcount_l, ++i;
            if(s[j] == 'x') ++xcount_r, --j;
            if(s[i] == s[j] && s[i] != 'x') {
                ans += abs(xcount_l - xcount_r);
                xcount_l = xcount_r = 0;
                ++i;
                --j;
            }
        }
        ans += abs(xcount_l - xcount_r);
        cout << ans << endl;
    }
}
