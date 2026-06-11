#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize(3)
#define debug(x) cout<<"#"<<x<<endl
#define pb push_back
#define fi first
#define se second
#define rep(i,l,h) for(int i=(l);i<=(h);++i)
#define drep(i,h,l) for(int i=(h);i>=(l);--i)
#define mem(x,y) memset(x,y,sizeof(x))
typedef pair<int,int>pii;

const int MAXN=2e5+5;
int n,A[MAXN],B[MAXN],a[MAXN],b[MAXN];
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  int ans=0;
  rep(i,1,n)cin>>A[i];
  rep(i,1,n)cin>>B[i];
  rep(k,0,28){
    int T=(1<<k);
    int MOD=T*2;
    rep(i,1,n) a[i]=A[i]%MOD;
    rep(i,1,n) b[i]=B[i]%MOD;
    sort(b+1,b+1+n);
    int cnt=0;
    rep(i,1,n){
      cnt+=upper_bound(b+1,b+1+n,T*2-a[i]-1)-lower_bound(b+1,b+1+n,T-a[i]);
      cnt+=upper_bound(b+1,b+1+n,T*4-a[i]-1)-lower_bound(b+1,b+1+n,3*T-a[i]);
    }//上下界好烦
    if(cnt%2==1)ans+=T;
  }
  cout<<ans<<endl;
  return 0;
}//Arc092 T2
