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
  int N;
  cin>>N;
  string S;
  cin>>S;
  vector<char> arr;
  map<char, int> amap, bmap;
  for(int i=0;i<N;++i) {
    if(amap[S[i]]==0) arr.push_back(S[i]);
    amap[S[i]]++;
  }
  for(int i=N;i<2*N;++i) bmap[S[i]]++;
  bool can = true;
  for(int i=0;i<arr.size();++i) {
    if(amap[arr[i]]!=bmap[arr[i]]) can = false;
  }
  if(!can) {
    cout<<0<<endl;
    return 0;
  }
  map<pair<string, string>, ll> cmap;
  string tmp1, tmp2;
  vector<string> arr1;
  for(int bit=0;bit<(1<<N);++bit) {
    tmp1.clear();
    tmp2.clear();
    for(int i=0;i<N;++i) {
      if((bit&(1<<i))!=0) tmp1.push_back(S[i+N]);
      else tmp2.push_back(S[i+N]);
    }
    reverse(tmp2.begin(), tmp2.end());
    cmap[mp(tmp1, tmp2)]++;
  }
  ll ans = 0;
  for(int bit=0;bit<(1<<N);++bit) {
    tmp1.clear();
    tmp2.clear();
    for(int i=0;i<N;++i) {
      if((bit&(1<<i))!=0) tmp1.push_back(S[i]);
      else tmp2.push_back(S[i]);
    }
    reverse(tmp2.begin(), tmp2.end());
    ans += cmap[mp(tmp2, tmp1)];
  }
  cout<<ans<<endl;
}

