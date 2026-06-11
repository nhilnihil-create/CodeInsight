#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)

typedef pair<int,int> P;
typedef long long ll;

const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    string S,T;
    cin >> S >> T;

    //vector<int> d(26,-1);
    map<int,int> d_s,d_t;

    string ans = "Yes";
    rep(i,S.size()) {
        int idx_s,idx_t;
        idx_s = S[i] - 'a';
        idx_t = T[i] - 'a';
        
        if (!d_s.count(idx_s)) {
            d_s[idx_s] = idx_t;
        }
        if (!d_t.count(idx_t)) {
            d_t[idx_t] = idx_s;
        }

        if (d_s[idx_s]==idx_t && d_t[idx_t]==idx_s) {
            continue;
        }
        else {
            ans = "No";

            break;
        }
    }
    cout << ans << endl;
}
