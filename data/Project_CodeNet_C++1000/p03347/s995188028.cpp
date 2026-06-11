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
  int N;
  cin>>N;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  if(A[0]>0) {
    cout<<-1<<endl;
    return 0;
  }
  bool can = true;
  ll ans = A[N-1];
  for(int i=N-1;i>=1;--i) {
    if(A[i-1]>A[i]-1) {
      ans += A[i-1];
    }
    else if(A[i-1]<A[i]-1) can = false;
  }
  if(!can) cout<<-1<<endl;
  else cout<<ans<<endl;
}

