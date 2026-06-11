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
  int N, M;
  cin>>N;
  map<string, int> amap;
  map<string, int> bmap;
  vector<string> arr;
  string tmp;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    if(bmap[tmp]==0) arr.push_back(tmp);
    amap[tmp]++;
    bmap[tmp]++;
  }
  cin>>M;
  for(int i=0;i<M;++i) {
    cin>>tmp;
    if(bmap[tmp]==0) arr.push_back(tmp);
    amap[tmp]--;
    bmap[tmp]++;
  }
  int ans = 0;
  for(int i=0;i<arr.size();++i) ans = max(ans, amap[arr[i]]);
  cout<<ans<<endl;
}

