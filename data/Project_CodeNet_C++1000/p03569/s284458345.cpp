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
  string S;
  cin>>S;
  int l=0, r=S.size()-1;
  int ans = 0;
  bool can = true;
  while(l<r) {
    if(S[l]==S[r]) {
      l++;
      r--;
    }
    else {
      if(S[l]=='x') {
        ans++;
        l++;
      }
      else if(S[r]=='x') {
        ans++;
        r--;
      }
      else {
        can = false;
        break;
      }
    }
  }
  if(can) cout<<ans<<endl;
  else cout<<-1<<endl;
}

