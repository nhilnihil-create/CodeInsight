#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> A(M);

    rep(i,M) {
        int k;
        cin >> k;
        rep(j,k) {
            int s;
            cin >> s;
            s--;
            A[i].push_back(s);
        }
    }

    vector<int> P;
    rep(i,M) {
        int p;
        cin >> p;
        P.push_back(p);
    }

    int ans = 0;
    for(int bit=0; bit<(1<<N); bit++) {
        vector<int> C(M,0);
        rep(m,M) {
            rep(i,A[m].size()) {
                if (bit & (1<<A[m][i])) {
                    C[m]++;
                }
            }
        }
        bool t = true;
        rep(i,M) {
            if (C[i]%2 != P[i]) t = false;
        }
        if (t) ans++;
    }
    cout << ans << endl;

}
