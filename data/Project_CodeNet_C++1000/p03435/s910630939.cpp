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
  int C[3][3];
  for(int i=0;i<3;++i) {
    for(int j=0;j<3;++j) {
      cin>>C[i][j];
    }
  }
  bool can = true;
  int sum = 0;
  for(int i=0;i<3;++i) {
    for(int j=0;j<3;++j) {
      sum += C[i][j];
    }
  }
  if(sum%3!=0) can = false;
  sum = 0;
  for(int i=0;i<2;++i) {
    for(int j=0;j<2;++j) {
      sum += C[i][j];
    }
  }
  if(sum%2!=0) can = false;
  sum = 0;
  for(int i=1;i<3;++i) {
    for(int j=0;j<2;++j) {
      sum += C[i][j];
    }
  }
  if(sum%2!=0) can = false;
  sum = 0;
  for(int i=1;i<3;++i) {
    for(int j=1;j<3;++j) {
      sum += C[i][j];
    }
  }
  if(sum%2!=0) can = false;
  sum = 0;
  for(int i=0;i<2;++i) {
    for(int j=1;j<3;++j) {
      sum += C[i][j];
    }
  }
  if(sum%2!=0) can = false;
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

