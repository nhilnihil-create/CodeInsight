#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  sort(all(a));
  reverse(all(a));
  int al=0;
  int b=0;
  rep(i,n){
    if(i%2==0)al+=a[i];
    else b+=a[i];
  }
  cout<<al-b<<endl;
  
    
    
  return 0;
}
