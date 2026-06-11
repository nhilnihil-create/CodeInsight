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
  int N, A, B, C;
  cin>>N>>A>>B>>C;
  int l[N];
  for(int i=0;i<N;++i) cin>>l[i];
  vector<int> arr1, arr2;
  int num1, num2;
  int tmp1, tmp2;
  int ans = inf;
  int tmp;
  int tmpnum1, tmpnum2;
  int len1, len2;
  for(int bit1=0;bit1<(1<<N);++bit1) {
    arr1.clear();
    arr2.clear();
    for(int i=0;i<N;++i) {
      if((bit1&(1<<i))==0) arr1.push_back(i);
      else arr2.push_back(i);
    }
    num1 = arr1.size();
    num2 = arr2.size();
    tmp1 = inf;
    tmp2 = inf;
    if(num1==0 || num2==0) continue;
    for(int bit2=0;bit2<(1<<num1);++bit2) {
      tmpnum1=0;
      tmpnum2=0;
      len1=0;
      len2=0;
      for(int i=0;i<num1;++i) {
        if((bit2&(1<<i))==0) {
          tmpnum1++;
          len1 += l[arr1[i]];
        }
        else {
          tmpnum2++;
          len2 += l[arr1[i]];
        }
      }
      if(tmpnum1==0 || tmpnum2==0) continue;
      tmp = 10*(tmpnum1-1)+10*(tmpnum2-1)+abs(A-len1)+abs(B-len2);
      tmp1 = min(tmp1, tmp);
    }
    for(int bit2=0;bit2<(1<<num2);++bit2) {
      tmpnum1=0;
      len1=0;
      for(int i=0;i<num2;++i) {
        if((bit2&(1<<i))==0) {
          tmpnum1++;
          len1 += l[arr2[i]];
        }
      }
      if(tmpnum1==0) continue;
      tmp = 10*(tmpnum1-1)+abs(C-len1);
      tmp2 = min(tmp2, tmp);
    }
    ans = min(ans, tmp1+tmp2);
  }
  cout<<ans<<endl;
}

