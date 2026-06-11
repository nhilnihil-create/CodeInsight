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
 int a,b,k;
  cin>>a>>b>>k;
  int c=0;
  int ans=0;
  for(int i=min(a,b);i>=1;i--){
    if(a%i==0&&b%i==0) c++;
    if(c==k) {
      ans=i;
      break;
    }
  }
  cout<<ans<<endl;
}

