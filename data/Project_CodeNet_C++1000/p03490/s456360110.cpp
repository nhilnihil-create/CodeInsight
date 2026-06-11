#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

string s;
vector<int> ax[2];
int x[2];
bool dp[2][16001];

int main(){
    cin >> s >> x[0] >> x[1];
    {
        int now = 0;
        int con = 0;
        int i = 0;
        for ( ; i < s.size(); i++) {
            if (s[i] != 'F') {
                break;
            }
        }
        if (i) x[0] -= i;
        for ( ; i < s.size(); i++) {
            if (s[i] == 'T') {
                if (con > 0) ax[now].push_back(con);
                now ^= 1;
                con = 0;
                continue;
            }
            con++;
        }
        if (con > 0) ax[now].push_back(con);
    }
    if (x[0] < -8000 || x[0] > 8000) {
        cout << "No" << endl;
        return 0;
    }
    rep(i,2) {
        memset(dp, 0, sizeof(dp));
        dp[0][8000] = true;
        int ho = 0, ge = 1;
        rep(j,ax[i].size()) {
            rep(k,16001) {
                if (dp[ho][k]) {
                    if (k+ax[i][j] <= 16000) dp[ge][k+ax[i][j]] = true;
                    if (k-ax[i][j] >= 0) dp[ge][k-ax[i][j]] = true;
                }
            }
            swap(ho, ge);
            memset(dp[ge], 0, sizeof(dp[ge]));
        }
        if (!dp[ho][x[i]+8000]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}






























