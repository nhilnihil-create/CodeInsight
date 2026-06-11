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
    string s; cin >> s;
    string S;
    rep(i, s.size() - 1) {
        if(s[i] == 'B' && s[i + 1] == 'C') {
            S.pb('D');
            i += 1;
        }else {
            S.pb(s[i]);
        }
    }
    ll cntA = 0;
    ll ans = 0;
    rep(i, S.size()) {
        if(S[i] == 'B' || S[i] == 'C') {
            cntA = 0;
        }else {
            if(S[i] == 'A') ++cntA;
            else if(S[i] == 'D') ans += cntA;
        }
    }
    cout << ans << endl;
}
