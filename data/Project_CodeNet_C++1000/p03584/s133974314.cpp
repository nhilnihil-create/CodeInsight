#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n),b(n),c(31);
  rep(i,n) cin >> a[i] >> b[i];
  vector<vector<int>> d(n,vector<int>(31));
  rep(i,31){
      c[i]=k%2;
      k/=2;
  }
  rep(i,n){
      rep(j,31){
      d[i][j]=a[i]%2;
      a[i]/=2;
      }
  }
    ll ans=0;
    for (int i=30;i>=0;i--){
        ll u=0;
        if (c[i]==0) continue;
        rep(j,n){
            bool t=true;
            for (int ii=30;ii>i;ii--){
                if (c[ii]==0 && d[j][ii]==1) t=false;
            }
            if (d[j][i]==1) t=false;
            if (t) u+=b[j];
        }
        ans=max(ans,u);
    }
    ll y=0;
    rep(i,n){
        bool t=true;
        rep(j,31){
            if (c[j]==0 && d[i][j]==1) t=false;
        }
        if (t) y+=b[i];
    }
    ans=max(ans,y);
    cout << ans << endl;
}
