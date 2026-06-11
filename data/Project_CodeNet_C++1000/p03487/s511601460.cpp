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
  ll N;
  cin>>N;
  ll tmp;
  vector<ll> arr;
  map<ll, ll> amap;
  for(ll i=0;i<N;++i) {
    cin>>tmp;
    if(amap[tmp]==0) arr.push_back(tmp);
    amap[tmp]++;
  }
  ll ans = 0;
  for(ll i=0;i<arr.size();++i) {
    if(arr[i]>amap[arr[i]]) ans += amap[arr[i]];
    else if(arr[i]<amap[arr[i]]) ans += amap[arr[i]] - arr[i];
  }
  cout<<ans<<endl;
}

