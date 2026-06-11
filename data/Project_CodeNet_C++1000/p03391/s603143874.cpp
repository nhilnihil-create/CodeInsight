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
  vector<tuple<ll, ll, ll> > arr(N);
  ll A, B;
  for(int i=0;i<N;++i) {
    cin>>A>>B;
    arr[i] = make_tuple(A-B, A, B);
  }
  sort(arr.begin(), arr.end());
  if(get<0>(arr[0])==0) {
    cout<<0<<endl;
    return 0;
  }
  ll sum = 0;
  ll h = big;
  for(int i=0;i<N;++i) {
    sum += get<2>(arr[i]);
    if(get<0>(arr[i])>0) {
      h = min(h, get<2>(arr[i]));
    }
  }
  cout<<sum-h<<endl;
}
