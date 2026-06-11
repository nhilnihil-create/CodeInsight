#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int c[3][3];
    rep(i,3) {
        rep(j,3) {
            cin >> c[i][j];
        }
    }
    
    string ans = "No";

    rep(i,c[0][0]+1) {
        rep(j,c[1][2]+1) {
            rep(k,c[2][2]+1) {
                bool tmp = true;
                int a[3],b[3];
                a[0] = i;
                a[1] = j;
                a[2] = k;
                b[0] = c[0][0]-a[0];
                b[1] = c[1][1]-a[1];
                b[2] = c[2][2]-a[2];

                rep(ii,3) {
                    rep(jj,3) {
                        if (c[ii][jj]!=a[ii]+b[jj]) {
                            tmp = false;
                        }
                    }
                }
                if (tmp) {
                    ans = "Yes";
                }
            }
        }
    }

    cout << ans << endl;

}
