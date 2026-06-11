#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;
 
int main() {
    int n,c;
    cin >> n >> c;
    vector<vector<int>> d(c,vector<int>(c)),t(3,vector<int>(c));
    rep(i,c) {
        rep(j,c) cin >> d[i][j];
    }
    int tin;
    rep(i,n) {
        rep(j,n) {
            cin >> tin;
            ++t[(i+j)%3][tin-1];
        }
    }
    int ans=1000000000;
    rep(i,c) {
        rep(j,c) {
            rep(k,c) {
                if (i==j || j==k || k==i) continue;
                int tans=0;
                rep(l,c) {
                    tans+=t[0][l]*(d[l][i]);
                    tans+=t[1][l]*(d[l][j]);
                    tans+=t[2][l]*(d[l][k]);
                }
                ans=min(ans,tans);
            }
        }
    }
    cout << ans << endl;
}