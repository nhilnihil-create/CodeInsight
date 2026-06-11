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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

pair<ll, ll> DP1[1000000], DP2[1000000];

int main() {
  ll N;
  cin>>N;
  ll A[(1<<N)];
  for(ll i=0;i<(1<<N);++i) {
    cin>>A[i];
  }
  DP1[0] = mp(A[0], 0);
  bool ok1;
  for(ll i=1;i<(1<<N);++i) {
    DP1[i] = mp(A[i], i);
    for(ll j=0;j<20;++j) {
      if((i&(1<<j))!=0) {
        vector<pair<ll, ll> > tmparr(4);
        tmparr[0] = mp(DP1[i].fi, DP1[i].se);
        tmparr[1] = mp(DP2[i].fi, DP2[i].se);
        tmparr[2] = mp(DP1[i-(1<<j)].fi, DP1[i-(1<<j)].se);
        tmparr[3] = mp(DP2[i-(1<<j)].fi, DP2[i-(1<<j)].se);
        sort(tmparr.begin(), tmparr.end(), greater<pair<ll, ll> >());
        map<ll, ll> amap;
        ok1 = false;
        for(ll k=0;k<4;++k) {
          if(amap[tmparr[k].se]>0) continue;
          if(!ok1) {
            DP1[i] = tmparr[k];
            amap[tmparr[k].se]++;
            ok1 = true;
          }
          else {
            DP2[i] = tmparr[k];
            break;
          }
        }
      }
    }
  }
  ll ans[(1<<N)];
  //for(int i=1;i<(1<<N);++i) cout<<i<<" "<<DP1[i]<<" "<<DP2[i]<<endl;
  for(ll i=0;i<(1<<N);++i) ans[i] = 0;
  for(ll i=1;i<(1<<N);++i) {
    ans[i] = max(ans[i-1], DP1[i].fi+DP2[i].fi);
  }
  for(ll i=1;i<(1<<N);++i) cout<<ans[i]<<endl;
}

