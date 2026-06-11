#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  int N, K;
  cin>>N>>K;
  int V[N];
  for(int i=0;i<N;++i) cin>>V[i];
  int ans = 0;
  int tmp;
  for(int i=0;i<=N;++i) {
    for(int j=0;i+j<=K && i+j<=N;++j) {
      vector<int> arr;
      for(int k=0;k<i;++k) {
        arr.push_back(V[k]);
      }
      for(int k=0;k<j;++k) {
        arr.push_back(V[N-1-k]);
      }
      sort(arr.begin(), arr.end());
      tmp = 0;
      for(int k=0;k<arr.size();++k) {
        if(k<K-(i+j) && arr[k]<0) continue;
        tmp += arr[k];
      }
      ans = max(ans, tmp);
    }
  }
  cout<<ans<<endl;
}

