#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    string s[N]; rep(i, N) cin >> s[i];
    int cntA = 0, cntB = 0, cntAB = 0, ans = 0;
    rep(i, N) {
        rep(j, s[i].size() - 1) {
            if(s[i][j] == 'A' && s[i][j + 1] == 'B')
                ++ans;
        }
    }
    vector<bool> isAB(N, false);
    rep(i, N) {
        if(s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') {
            cntAB++;
            isAB[i] = true;
        }else if(s[i][0] == 'B') {
            cntB++;
        }else if(s[i][s[i].size() - 1] == 'A') {
            cntA++;
        }
    }
    if(cntAB > 0) {
        ans += cntAB - 1;
        cntAB = 1;
    }
    if(cntAB == 1) {
        if(cntA > 0) ++ans, --cntA;
        if(cntB > 0) ++ans, --cntB;
    }
    cout << ans + min(cntB, cntA) << endl;
}
