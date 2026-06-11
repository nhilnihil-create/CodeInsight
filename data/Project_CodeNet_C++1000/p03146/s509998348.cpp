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
  int s;
  cin>>s;
  int ok[11000];
  bool fin=false;
  int ans=0;
  while(!fin){
    ans++;
    //cout<<s<<endl;
    if(ok[s]==1) {
     // cout<<" "<<s<<endl;
      fin=true; 
      
    }
    else{
    ok[s]=1;
      if(s%2==0) s/=2;
      else s=3*s+1;
    }
  }
  cout<<ans<<endl;
}


