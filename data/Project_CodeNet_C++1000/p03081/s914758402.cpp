#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
int n,q;
int x;
char s[200050];
char t[200050];
char d[200050];
void input(){
  cin>>n>>q;
  rep1(i,n)cin>>s[i];
  rep(i,q)cin>>t[i]>>d[i];
  s[0]='0';
  s[q+1]='0';
}
void go(char d){
  if(d=='L')x--;
  if(d=='R')x++;
}
bool left(int p){
  x=p;
  rep(i,q){
    if(s[x]==t[i]){
      go(d[i]);
  }
  }
  return x==0;
}
bool right(int p){
  x=p;
  rep(i,q){
    if(s[x]==t[i]){
      go(d[i]);
  }
  }
  return x==n+1;
}
int main(){
  input();
  int l=0;
  int r=n+1;
  int mid;
  while(r-l>1){
    mid=(l+r)/2;
    if(left(mid))l=mid;
    else r=mid;
  }
  int limit_l=l;
  l=0;
  r=n+1;
  while(r-l>1){
    mid=(l+r)/2;
    if(right(mid))r=mid;
    else l=mid;
  }
  int limit_r=r;
  int ans=q-(q+1-limit_r)-limit_l;
  cout<<ans<<endl;
  return 0;
}
