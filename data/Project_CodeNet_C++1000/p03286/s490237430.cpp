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
  ll N;
  cin>>N;
  ll maxnum, minnum;
  ll tmp;
  string ans;
  for(int i=32;i>=0;--i) {
    tmp = 1;
    maxnum = 0;
    minnum = 0;
    for(int j=0;j<i;++j) {
      if(j%2==0) maxnum += tmp;
      else minnum += tmp;
      tmp *= -2;
    }
    if(minnum<=N-tmp && N-tmp<=maxnum) {
      ans.push_back('1');
      N -= tmp;
    }
    else {
      ans.push_back('0');
    }
  }
  bool ok = false;
  for(int i=0;i<ans.size();++i) {
    if(ok) cout<<ans[i];
    else {
      if(ans[i]=='1') {
        ok = true;
        cout<<ans[i];
      }
    }
  }
  if(!ok) cout<<0<<endl;
}

