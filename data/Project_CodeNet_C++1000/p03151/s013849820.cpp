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
  int N;
  cin>>N;
  ll A[N], B[N];
  for(int i=0;i<N;++i) cin>>A[i];
  for(int i=0;i<N;++i) cin>>B[i];
  vector<int> arr(N);
  for(int i=0;i<N;++i) {
    arr[i] = A[i]-B[i];
  }
  sort(arr.begin(), arr.end());
  int ans = 0;
  ll sum = 0;
  for(int i=0;i<N;++i) {
    if(arr[i]<0) {
      ans++;
      sum += arr[i];
    }
  }
  for(int i=N-1;i>=0;--i) {
    if(sum>=0) break;
    if(arr[i]<=0) break;
    ans++;
    sum += arr[i];
  }
  if(sum>=0) cout<<ans<<endl;
  else cout<<-1<<endl;
}
