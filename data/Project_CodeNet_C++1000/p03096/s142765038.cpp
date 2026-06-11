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

ll DP[200005];

int main() {
  int N;
  cin>>N;
  vector<int> C;
  int tmp;
  cin>>tmp;
  C.push_back(tmp);
  for(int i=1;i<N;++i) {
    cin>>tmp;
    if(C[C.size()-1]!=tmp) C.push_back(tmp);
  }
  map<int, int> amap;
  map<int, int> bmap;
  for(int i=C.size()-1;i>=0;--i) {
    if(bmap[C[i]]!=0) {
      amap[i] = bmap[C[i]];
    }
    bmap[C[i]] = i;
  }
  for(int i=0;i<C.size();++i) {
    if(i==0) DP[i] = 1;
    else {
      DP[i] += DP[i-1];
      DP[i] %= mod;
    }
    if(i<amap[i]) {
      DP[amap[i]] += DP[i];
      DP[amap[i]] %= mod;
    }
  }
  cout<<DP[C.size()-1]<<endl;
}

