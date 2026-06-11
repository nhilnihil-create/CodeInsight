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
  double n, m, d;
  cin>>n>>m>>d;
  if(d==0) cout<<setprecision(20)<<(n-d)*(m-1)/(n*n)<<endl;
  else cout<<setprecision(20)<<2*(n-d)*(m-1)/(n*n)<<endl;
}

