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
  int N;
  cin>>N;
  vector<int> oldarr(N), newarr;
  for(int i=0;i<N;++i) cin>>oldarr[i];
  vector<int> ans;
  bool can;
  int index;
  for(int i=0;i<N;++i) {
    newarr.clear();
    can = false;
    for(int j=oldarr.size()-1;j>=0;--j) {
      if(oldarr[j]==j+1) {
        can = true;
        index = j;
        ans.push_back(oldarr[j]);
        break;
      }
    }
    if(!can) break;
    for(int j=0;j<oldarr.size();++j) {
      if(j==index) continue;
      newarr.push_back(oldarr[j]);
    }
    oldarr = newarr;
  }
  if(!can) {
    cout<<-1<<endl;
    return 0;
  }
  for(int i=N-1;i>=0;--i) {
    cout<<ans[i]<<endl;
  }
}
