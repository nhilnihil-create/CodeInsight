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
  int A, B, C, X;
  cin>>A>>B>>C>>X;
  int ans = 0;
  for(int i=0;i<=A;++i) {
    for(int j=0;j<=B;++j) {
      if(X-500*i-100*j>=0 && (X-500*i-100*j)/50<=C) ans++;
    }
  }
  cout<<ans<<endl;
}
