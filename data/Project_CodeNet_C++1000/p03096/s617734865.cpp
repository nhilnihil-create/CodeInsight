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
    if(C[C.size()-1]==tmp) continue;
    C.push_back(tmp);
  }
  map<int, int> amap, bmap;
  for(int i=1;i<=200000;++i) amap[i] = -1;
  for(int i=0;i<C.size();++i) {
    if(amap[C[i]]>-1) bmap[amap[C[i]]] = i;
    amap[C[i]] = i;
  }
  DP[0] = 1;
  if(bmap[0]>0) DP[bmap[0]] += DP[0];
  for(int i=1;i<N;++i) {
    DP[i] += DP[i-1];
    DP[i] %= mod;
    if(bmap[i]>0) {
      DP[bmap[i]] += DP[i];
      DP[bmap[i]] %= mod;
    }
  }
  cout<<DP[N-1]<<endl;
}

