#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, M;
  cin>>N>>M;
  vector<ll> yaku;
  for(ll i=1;i*i<=M;++i) {
    if(M%i==0) {
      yaku.push_back(i);
      if(i!=M/i) yaku.push_back(M/i);
    }
  }
  ll ans = 1;
  for(int i=0;i<yaku.size();++i) {
    if(M>=N*yaku[i]) ans = max(ans, yaku[i]);
  }
  cout<<ans<<endl;
}

