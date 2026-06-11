#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll n,m,d;
  cin >> n >> m >> d;


  double x = (n-d)*(m-1);
  if(d!=0){
    x*=2;
  }
  double ans=x/(n*n);
  cout << fixed << setprecision(10) << ans << endl;
}