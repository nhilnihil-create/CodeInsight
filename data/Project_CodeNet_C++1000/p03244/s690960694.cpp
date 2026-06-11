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
  int N;
  cin>>N;
  int v[N];
  vector<int> arr1, arr2;
  map<int, int> amap, bmap;
  for(int i=0;i<N;++i) {
    cin>>v[i];
    if(i%2==0) {
      if(amap[v[i]]==0) arr1.push_back(v[i]);
      amap[v[i]]++;
    }
    else {
      if(bmap[v[i]]==0) arr2.push_back(v[i]);
      bmap[v[i]]++;
    }
  }
  vector<pair<int, int> > arr11, arr22;
  for(int i=0;i<arr1.size();++i) arr11.push_back(mp(amap[arr1[i]], arr1[i]));
  for(int i=0;i<arr2.size();++i) arr22.push_back(mp(bmap[arr2[i]], arr2[i]));
  sort(arr11.begin(), arr11.end(), greater<pair<int, int> >());
  sort(arr22.begin(), arr22.end(), greater<pair<int, int> >());
  int ans = inf;
  if(arr11[0].se!=arr22[0].se) {
    ans = min(ans, N-arr11[0].fi-arr22[0].fi);
  }
  else if(arr11.size()>1 && arr22.size()>1) {
    ans = min(ans, N-arr11[0].fi-arr22[1].fi);
    ans = min(ans, N-arr11[1].fi-arr22[0].fi);
  }
  else if(arr11.size()==1 && arr22.size()>1) {
    ans = min(ans, N-arr11[0].fi-arr22[1].fi);
    ans = min(ans, N-arr22[0].fi);
  }
  else if(arr11.size()>1 && arr22.size()==1) {
    ans = min(ans, N-arr22[0].fi-arr11[1].fi);
    ans = min(ans, N-arr11[0].fi);
  }
  else {
    ans = min(ans, N-arr11[0].fi);
    ans = min(ans, N-arr22[0].fi);
  }
  cout<<ans<<endl;
}

