#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
vector<ll> a,b,c;
void make_edge(ll x,ll y,ll z){
    a.push_back(x+1);
    b.push_back(y+1);
    c.push_back(z);
}
int main(){
  ll L; cin>>L;
  ll n=0,x=1;
  for(;x<=L;n++){x*=2;}
  for(int i=0;i<n-1;i++){
      make_edge(i,i+1,(1<<(n-i-2)));
      make_edge(i,i+1,0);
  }
  for(int i=1;i<n;i++){
      if((L&(1LL<<(n-1-i)))==0)continue;
      ll p=L/(1LL<<(n-i));
      p*=(1<<(n-i));
      make_edge(0,i,p);
  }
  cout<<n<<" "<<a.size()<<endl;
  for(int i=0;i<a.size();i++){
      cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
  }
  return 0;
}
