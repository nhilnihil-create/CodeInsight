#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll n,m,d;
  cin>>n>>m>>d;
  long double ans = (2*(long double)(n-d)/n)*((long double)(m-1LL)/n);
  if(d==0) ans/=2;
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
}