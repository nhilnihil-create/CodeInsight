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
  vector<ll> A(N);
  map<ll, int> amap;
  for(int i=0;i<N;++i) {
    cin>>A[i];
    amap[A[i]]++;
  }
  sort(A.begin(), A.end(), greater<ll>());
  int ans = 0;
  ll two;
  for(int i=0;i<N;++i) {
    if(amap[A[i]]==0) continue;
    for(int j=30;j>=0;--j) {
      if((A[i]&(1<<j))!=0) {
        two = (1<<(j+1));
        break;
      }
    }
    if(A[i]==two-A[i]) {
      if(amap[A[i]]>=2) {
        ans++;
        amap[A[i]] -= 2;
      }
    }
    else {
      if(amap[two-A[i]]>=1) {
        ans++;
        amap[A[i]]--;
        amap[two-A[i]]--;
      }
    }
  }
  cout<<ans<<endl;
}

