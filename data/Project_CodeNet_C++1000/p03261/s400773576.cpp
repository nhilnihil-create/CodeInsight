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
  string tmp, tmp1;
  bool ok = true;
  map<string, int> amap;
  cin>>tmp;
  amap[tmp]++;
  tmp1 = tmp;
  for(int i=1;i<N;++i) {
    cin>>tmp;
    if(amap[tmp]>0) ok = false;
    if(tmp[0]!=tmp1[tmp1.size()-1]) ok = false;
    amap[tmp]++;
    tmp1 = tmp;
  }
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

