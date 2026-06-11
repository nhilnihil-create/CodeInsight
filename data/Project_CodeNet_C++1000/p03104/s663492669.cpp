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
  ll A, B;
  cin>>A>>B;
  ll ans;
  ll num;
  if(A%2==0) {
    if(B%2==0) {
      num = (B-A)/2;
      num %= 2;
      ans = B^num;
    }
    else {
      num = (B-A+1)/2;
      num %= 2;
      ans = num;
    }
  }
  else {
    if(B%2==0) {
      num = (B-A)/2;
      num %= 2;
      ans = A^B^num;
    }
    else {
      num = (B-A)/2;
      num %= 2;
      ans = A^num;
    }
  }
  cout<<ans<<endl;
}
