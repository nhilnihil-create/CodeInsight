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
  int n,q;
  string s;
  cin>>n>>q>>s;
  vector<int>l(q);
  vector<int>r(q);
  
  vector<ll>a(n);
  int tmp=0;
  Rep(i,1,n){
    if(s[i]=='C'&&s[i-1]=='A')tmp++;
    a[i]=tmp;
  }
  
  rep(i,q){cin>>l[i]>>r[i];
    cout<<a[r[i]-1]-a[l[i]-1]<<endl;
  }
    
    
  return 0;
}
