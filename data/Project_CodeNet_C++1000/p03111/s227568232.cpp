#include "bits/stdc++.h"
 
using namespace std;
typedef int64_t ll;
typedef vector<int64_t> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<vd> vvd;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define SIZE(a) int((a).size())
int n,A,B,C;vll l(8);
int dfs(ll x,ll a,ll b,ll c){
  if(x==n){
    if(a==0||b==0||c==0){
      return 1e9;
    }
    else{return abs(a-A)+abs(b-B)+abs(c-C)-30;}
  }
  else{
    int no=dfs(x+1,a,b,c);
    no=min(no,dfs(x+1,a+l[x],b,c)+10);
    no=min(no,dfs(x+1,a,b+l[x],c)+10);
    no=min(no,dfs(x+1,a,b,c+l[x])+10);
    return no;
  }
}
int main(){
  cin>>n>>A>>B>>C;
  rep(i,0,n){
    cin>>l[i];
  }
  cout<<dfs(0,0,0,0)<<endl;
}