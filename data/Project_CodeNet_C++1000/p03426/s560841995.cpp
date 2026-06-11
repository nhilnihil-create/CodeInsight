#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)

typedef pair<int,int> P;
typedef long long ll;

const int INF = 1001001001;
const int mod = 1000000007;
const double PI=acos(-1);

int main(){
    ll H,W,D;
    cin >> H >> W >> D;
    vector<pair<ll,pair<ll,ll>>> A;

    rep(h,H) {
        rep(w,W) {
            ll tmp;
            cin >> tmp;
            A.push_back(make_pair(tmp,make_pair(h,w)));
        }
    }
    sort(A.begin(),A.end());

    ll dp[W*H] = {};
    rep(i,W*H) {
        if (i<D) {
            dp[i] = 0;
        }
        else {
            dp[i] = dp[i-D] + abs(A[i].second.first - A[i-D].second.first) + abs(A[i].second.second - A[i-D].second.second);
        }
    }

    int Q;
    cin >> Q;

    rep(i,Q) {
        int L,R;
        cin >> L >> R;
        L--;
        R--;
        cout << dp[R]-dp[L] << endl;
    }


}
