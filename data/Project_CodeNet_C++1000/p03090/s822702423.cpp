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
  int N;
  cin>>N;
  vector<pair<int, int> > ans;
  if(N%2==0) {
    for(int i=1;i<=N;++i) {
      for(int j=i+1;j<=N;++j) {
        if(i+j==N+1) continue;
        ans.push_back(mp(i, j));
      }
    }
  }
  else {
    for(int i=1;i<=N;++i) {
      for(int j=i+1;j<=N;++j) {
        if(i+j==N) continue;
        ans.push_back(mp(i, j));
      }
    }
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();++i) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
}

