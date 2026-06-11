#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define fix(n) cout<<fixed<<setprecision(n)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
using namespace std;
typedef long long ll;
const ll mod=1000000007;
double pi=3.1415926535;

int main(){
  int n,c,aa,ans=-1000000000;
  cin>>n;
  int a[n][10],b[n][11];
  rep(i,0,n) rep(j,0,10) cin>>a[i][j];
  rep(i,0,n) rep(j,0,11) cin>>b[i][j];
  rep(i,1,1024){
    aa=i;
    vector<int> d(n);
    rep(j,0,10){
      if(aa%2==1) rep(k,0,n) d[k]+=a[k][j];
      aa/=2;
    }
    rep(j,0,n) c+=b[j][d[j]];
    ans=max(ans,c);
    c=0;
  }
  co(ans);
  
  return 0;
}