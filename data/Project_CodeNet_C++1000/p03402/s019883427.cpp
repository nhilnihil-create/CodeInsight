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
  int A, B;
  cin>>A>>B;
  char ans[100][100];
  for(int i=0;i<100;++i) {
    for(int j=0;j<100;++j) {
      if(i<50) ans[i][j] = '.';
      else ans[i][j] = '#';
    }
  }
  A--;
  B--;
  for(int i=1;i<49;++i) {
    if(B==0) break;
    if(i%2==0) continue;
    for(int j=1;j<99;++j) {
      if(B==0) break;
      if(ans[i-1][j]=='.' && ans[i][j-1]=='.') {
        ans[i][j] = '#';
        B--;
      }
    }
  }
  for(int i=51;i<100;++i) {
    if(A==0) break;
    if(i%2==0) continue;
    for(int j=1;j<99;++j) {
      if(A==0) break;
      if(ans[i-1][j]=='#' && ans[i][j-1]=='#') {
        ans[i][j] = '.';
        A--;
      }
    }
  }
  cout<<100<<" "<<100<<endl;
  for(int i=0;i<100;++i) {
    for(int j=0;j<100;++j) {
      cout<<ans[i][j];
    }
    cout<<endl;
  }
}

