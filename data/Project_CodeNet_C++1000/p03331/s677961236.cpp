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

int keta(int n) {
  int ten = 1000000;
  int ans = 0;
  while(ten>0) {
    ans += n/ten;
    n %= ten;
    ten /= 10;
  }
  return ans;
}

int main() {
  int N;
  cin>>N;
  int ans1=1, ans2=N-1;
  int tmpans = keta(ans1)+keta(ans2);
  for(int i=1;i<N;++i) {
    if(tmpans>keta(i)+keta(N-i)) {
      ans1 = i;
      ans2 = N-i;
      tmpans = keta(i)+keta(N-i);
    }
  }
  cout<<keta(ans1)+keta(ans2)<<endl;
}

