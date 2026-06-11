#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const ll INF=2e18;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int h,w;
    cin >> h >> w;
    vector<vector<int>> c(10,vector<int>(10));
    rep(i,10){
        rep(j,10) cin >> c[i][j];
    } 
    rep(k,10) {
        rep(i,10) {
            rep(j,10) {
                int cc=c[i][k]+c[k][j];
                if (cc<c[i][j]) c[i][j]=cc;
            }
        }
    }
    ll ans=0;
    rep(i,h) {
        rep(j,w) {
            int a;
            cin >> a;
            if (a*a!=1) ans+=c[a][1];
        }
    }
    cout << ans << endl;
    
    return 0;
}
