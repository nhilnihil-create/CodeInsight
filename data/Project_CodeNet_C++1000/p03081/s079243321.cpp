#include<iostream>
#include<vector>
using namespace std;
bool solve(string s,vector<pair<char,char>>q,int p,int n){
  for(int i=0;i<q.size()&&p!=n;i++)if(q[i].first==s[p])p+=(q[i].second=='R'?1:-1);
  return p==n?true:false;
}
int main(){
  int n,q,ok,ng,ans;
  cin>>n>>q;
  ans=n;
  string s;
  cin>>s;
  s="0"+s+"0";

  vector<pair<char,char>>Q(q);
  for(int i=0;i<q;i++)cin>>Q[i].first>>Q[i].second;

  ok=1,ng=n+1;
  while(abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    if(solve(s,Q,mid,0))ok=mid;
    else ng=mid;
  }
  ans-=ok;

  ok=n+1,ng=1;
  while(abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    if(solve(s,Q,mid,n+1))ok=mid;
    else ng=mid;
  }
  ans-=(n-ok+1);

  cout<<ans<<endl;
  return 0;
}