#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<long long,long long>;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD= 1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  int n;
  string s;
  cin >> n >> s;
  
  map<pair<string,string>,ll>mp;
  for(int bit=0;bit<(1<<n);bit++){
    string u="", v="";
    rep(i,n){
      if(bit & (1<<i)){
        u+=s[2*n-1-i];
      }
      else v+=s[2*n-1-i];
    }
    auto p=make_pair(u,v);
    mp[p]++;
  }
  
  ll ans=0;
  for(int bit=0;bit<(1<<n);bit++){
    string u="", v="";
    rep(i,n){
      if(bit & (1<<i)){
        u+=s[i];
      }
      else v+=s[i];
    }
    auto p=make_pair(u,v);
    ans+=mp[p];
  }
  cout << ans << endl;
        
  
}
