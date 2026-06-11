#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<bool,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  vector<P> a;
  int cur=1;
  rep(i,0,n-1){
    if(s[i]==s[i+1]){
      cur++;
    }
    else{
      if(s[i]=='1'){
        a.push_back(P(true,cur));
      }
      else{
        a.push_back(P(false,cur));
      }
      cur=1;
    }
  }
  if(s[n-1]=='1'){
    a.push_back(P(true,cur));
  }
  else{
    a.push_back(P(false,cur));
  }
  int tr=0;
  int fa=0;
  rep(i,0,a.size()){
    if(a[i].first) tr++;
    else fa++;
  }
  
  if(fa<=k) cout<<n<<endl;
  else{
    int b[tr+fa+1];
    b[0]=0;
    rep(i,0,tr+fa){
      b[i+1]=b[i]+a[i].second;
    }
    
    if(a[0].first && a[tr+fa-1].first){
      int ans=0;
      for(int i=0;i+2*k+1<=tr+fa;i+=2){
        ans=max(ans,b[i+2*k+1]-b[i]);
      }
      cout<<ans<<endl;
    }
    else if(!a[0].first && a[tr+fa-1].first){
      int ans=b[2*k]-b[0];
      for(int i=1;i+2*k+1<=tr+fa;i+=2){
        ans=max(ans,b[i+2*k+1]-b[i]);
      }
      cout<<ans<<endl;
    }
    else if(a[0].first && !a[tr+fa-1].first){
      int ans=b[tr+fa]-b[tr+fa-2*k];
      for(int i=0;i+2*k+1<=tr+fa;i+=2){
        ans=max(ans,b[i+2*k+1]-b[i]);
      }
      cout<<ans<<endl;
    }
    else{
      int ans=max(b[2*k]-b[0],b[tr+fa]-b[tr+fa-2*k]);
      for(int i=1;i+2*k+1<=tr+fa;i+=2){
        ans=max(ans,b[i+2*k+1]-b[i]);
      }
      cout<<ans<<endl;
    }
  }
}