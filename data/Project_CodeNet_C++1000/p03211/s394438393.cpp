#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
 string s;
  cin>>s;
  int ans=inf;
  int n=s.size();
  rep(i,0,n-2){
   
     int g=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
     // cout<<g<<endl;
      ans=min(ans,abs(753-g)); 
   
  }
  cout<<ans<<endl;
}








