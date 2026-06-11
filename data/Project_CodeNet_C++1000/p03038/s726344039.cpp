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
  int N, M;
  cin>>N>>M;
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  vector<pair<ll, int> > arr(M);
  int b, c;
  for(int i=0;i<M;++i) {
    cin>>b>>c;
    arr[i] = mp(c, b);
  }
  sort(arr.begin(), arr.end(), greater<pair<ll, int> >() );
  int index = 0;
  for(int i=0;i<N;++i) {
    if(index==M) break;
    if(arr[index].se==0) {
      index++;
      i--;
      continue;
    }
    if(arr[index].fi>A[i]) {
      A[i] = arr[index].fi;
      arr[index].se--;
    }
  }
  ll ans = 0;
  for(int i=0;i<N;++i) {
    ans += A[i];
  }
  cout<<ans<<endl;
}

