#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int d,n;
  cin>>d>>n;
  if(n==100)n++;
  if(d==0){cout<<n<<endl;}
  else if(d==1){cout<<100*n<<endl;}
  else cout<<10000*n<<endl;
    
    
  return 0;
}
