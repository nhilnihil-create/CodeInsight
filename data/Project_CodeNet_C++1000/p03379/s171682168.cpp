#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
int dh[4] = {-1, 0, 0, 1};
int dw[4] = {0, -1, 1, 0}; 
using P = pair<int, int>;
const double pi = acos(-1.0);

int main(){
  int n;
  cin>>n;
  vector<ll>x(n);
  rep(i,n)cin>>x[i];
  vector<ll>y(n);
  y=x;
  sort(all(y));
  int m=n/2;
  int mida=y[m-1],midb=y[m];
  rep(i,n){
    if(x[i]<=mida)cout<<midb<<endl;
    else cout<<mida<<endl;
  }
  
  
    
    
  return 0;
}
