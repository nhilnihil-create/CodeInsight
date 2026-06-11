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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N;
  map<ll, ll> amap;
  ll D;
  for(int i=0;i<N;++i) {
    cin>>D;
    amap[D]++;
  }
  cin>>M;
  ll T;
  bool can = true;
  for(int i=0;i<M;++i) {
    cin>>T;
    if(amap[T]==0) can = false;
    amap[T]--;
  }
  if(can) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

