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

int keta(int x) {
  int ten = 100000;
  int ans = 0;
  while(ten>0) {
    ans += x/ten;
    x %= ten;
    ten /= 10;
  }
  return ans;
}

int main() {
  int N, A, B;
  cin>>N>>A>>B;
  int ans = 0;
  for(int i=1;i<=N;++i) {
    if(A<=keta(i) && keta(i)<=B) ans += i;
  }
  cout<<ans<<endl;
}
