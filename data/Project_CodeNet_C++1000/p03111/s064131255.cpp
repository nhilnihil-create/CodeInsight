#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  int l[n];
  rep(i,0,n) cin>>l[i];
  int ans=114514;
  rep(i,0,1<<(2*n)){
    int cur=i;
    int d=0;
    int e=0;
    int f=0;
    int mp=0;
    rep(j,0,n){
      if(cur%4==1){
        if(d!=0) mp+=10;
        d+=l[j];
      }
      else if(cur%4==2){
        if(e!=0) mp+=10;
        e+=l[j];
      }
      else if(cur%4==3){
        if(f!=0) mp+=10;
        f+=l[j];
      }
      cur/=4;
    }
    if(d!=0 && e!=0 && f!=0){
      mp+=abs(a-d);
      mp+=abs(b-e);
      mp+=abs(c-f);
      ans=min(ans,mp);
    }
  }
  cout<<ans<<endl;
}