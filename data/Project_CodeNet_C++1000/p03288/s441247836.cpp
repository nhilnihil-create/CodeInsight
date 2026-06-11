#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int r;
  cin>>r;
  if(r<1200)cout<<"ABC"<<endl;
  else if(r<2800)cout<<"ARC"<<endl;
  else cout<<"AGC"<<endl;
    
    
  return 0;
}
