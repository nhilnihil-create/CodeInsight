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

int main() {
  ll N, K;
  cin>>N>>K;
  vector<pair<ll, ll> > sushi(N);
  vector<vector<ll> > sushi1(N), sushi3(N);
  ll t;
  ll d;
  for(ll i=0;i<N;++i) {
    cin>>t>>d;
    t--;
    sushi[i] = mp(d, t);
    sushi1[t].push_back(d);
  }
  sort(sushi.begin(), sushi.end(), greater<pair<ll, ll> >());
  vector<ll> sushi2;
  ll seed=0, score=0;
  map<ll, ll> amap;
  for(ll i=0;i<K;++i) {
    if(amap[sushi[i].se]==0) seed++;
    amap[sushi[i].se]++;
    score += sushi[i].fi;
    sushi3[sushi[i].se].push_back(sushi[i].fi);
  }
  for(ll i=0;i<N;++i) {
    sort(sushi3[i].begin(), sushi3[i].end());
    if(sushi3[i].size()>0) for(ll j=0;j<sushi3[i].size()-1;++j) sushi2.push_back(sushi3[i][j]);
  }
  sort(sushi2.begin(), sushi2.end(), greater<ll>());
  vector<ll> ans;
  ans.push_back(score+seed*seed);
  for(ll i=K;i<N;++i) {
    if(amap[sushi[i].se]>0 || sushi2.size()==0) continue;
    score = score-sushi2[sushi2.size()-1]+sushi[i].fi;
    seed++;
    ans.push_back(score+seed*seed);
    sushi2.pop_back();
    amap[sushi[i].se]++;
  }
  sort(ans.begin(), ans.end(), greater<ll>());
  cout<<ans[0]<<endl;
}

