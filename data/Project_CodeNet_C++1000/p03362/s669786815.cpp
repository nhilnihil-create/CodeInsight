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
  bool prime[60000];
  for(int i=0;i<60000;++i) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
  for(int i=2;i<60000;++i) {
    if(!prime[i]) continue;
    for(int j=2;i*j<60000;++j) prime[i*j] = false;
  }
  int N;
  cin>>N;
  int num = 0;
  for(int i=0;i<60000;++i) {
    if(prime[i] && i%5==1) {
      cout<<i<<" ";
      num++;
    }
    if(num==N) break;
  }
}

