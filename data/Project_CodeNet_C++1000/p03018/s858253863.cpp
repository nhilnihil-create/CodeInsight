#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<long long,long long>;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  string s;
  cin >> s;
  ll n=s.size();
  ll ans=0,sum=0;
  rep(i,n-1){
    if(s[i]=='A')sum++;
    else if(s[i]=='B' && s[i+1]=='C'){
      ans+=sum;
      i++;
    }
    else sum=0;
  }
  cout << ans << endl;
}
