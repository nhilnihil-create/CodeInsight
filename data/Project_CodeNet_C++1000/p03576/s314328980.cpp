#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll gcd(ll a, ll b){
  if(b==0) return a;
  else gcd(b,a%b);
}
ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}
using Graph = vector<vector<int>>;

struct UnionFind{
  vector<int>par;
  UnionFind(int n):par(n){
    rep(i,n) par[i]=i;
  }
  int root(int x){
    if(par[x]==x)return x;
    return par[x]=root(par[x]);
  }
  
  void unite(int x, int y){
    int rx=root(x);
    int ry=root(y);
    if(rx==ry)return;
    par[rx]=ry;
  }
  bool same(int x,int y){
    int rx=root(x);
    int ry=root(y);
    return rx==ry;
  }
};


int main(){
  int n,K;
  cin >> n >> K;
  vector<ll>x(n);
  vector<ll>y(n);
  vector<ll>px(n);
  vector<ll>py(n);
  rep(i,n){
    cin >> x[i] >> y[i];
    px[i]=x[i];
    py[i]=y[i];
  }
  
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  
  ll ans= 4e18;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      for(int k=0;k<n-1;k++){
        for(int l=k+1;l<n;l++){
          ll lx=x[i];
      	  ll rx=x[j];
          ll ly=y[k];
          ll ry=y[l];
          int sum=0;
          rep(m,n){
            if(lx<=px[m] && ly<=py[m] && px[m]<=rx && py[m]<=ry) sum++;
          }
          if(sum>=K){
            ll s=(rx-lx)*(ry-ly);
            if(ans>s)ans=s;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
