#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF=1e18;
const ll MOD=1e9+7;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<int,int>mp;
  rep(i,n){
    mp[s[i]-'a']++;
  }
  ll ans=1;
  for(auto p:mp){
    p.second++;
    p.second%=MOD;
    ans*=p.second;
    ans%=MOD;
  }
  ans--;
  ans%=MOD;
  cout << ans << endl;
  
}
