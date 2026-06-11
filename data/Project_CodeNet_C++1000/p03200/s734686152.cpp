#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  string s;
  cin>>s;
  ll ans=0;
  ll b=0;
  rep(i,s.size()){
    if(s[i]=='B')b++;
    else ans+=b;
  }
  cout<<ans<<endl;
  return 0;
}
