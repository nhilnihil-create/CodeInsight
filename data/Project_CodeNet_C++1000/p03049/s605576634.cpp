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
int n;
  cin>>n;
  vector<string> s(n);
  ll ans=0;
  ll ba=0,a=0,b=0;
  rep(i,0,n) {
    cin>>s[i];
    ll m=s[i].size();
    rep(j,0,m-1){
      if(s[i][j]=='A'&&s[i][j+1]=='B') ans++;
    }
    if(s[i][0]=='B'&&s[i][m-1]=='A') ba++;
    else if(s[i][m-1]=='A') a++;
    else if(s[i][0]=='B') b++;
    
    
  }
  //cout<<ans<<" "<<a<<b<<ba<<endl;
  if(ba>1)ans+=ba-1;
  if(ba==0) ans+=min(a,b);
  else{
   a++;
    b++;
    if(a==1&&b==1) {
     a--;b--; 
    }
    ans+=min(a,b);
  }
  cout<<ans<<endl;
}

