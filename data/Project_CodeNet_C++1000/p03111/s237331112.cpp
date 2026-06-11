#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  vector<int> l(n);
  rep(i,n) cin>>l[i];
  
  vector<int> rui={1,4,16,64,256,1024,4096,16384,65536};
  int ans=1000000000;
  rep(bit,rui[n]){
    int res=0;
    int q=bit;
    int ka=0,kb=0,kc=0;
    rep(j,n){
      int p=q%4;
      q/=4;
      if(p==0) continue;
      else if(p==1){
        if(ka!=0) res+=10;
        ka+=l[j];
      }
      else if(p==2){
        if(kb!=0) res+=10;
        kb+=l[j];
      }
      else if(p==3){
        if(kc!=0) res+=10;
        kc+=l[j];    
      }
    }
    if(ka==0||kb==0||kc==0) continue;
    res+=abs(ka-a);
    res+=abs(kb-b);
    res+=abs(kc-c);
    ans=min(ans,res);
  }
  cout<<ans<<endl;
}