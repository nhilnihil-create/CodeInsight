#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 10e9+7;

#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prtd(n, var)  cout << setprecision(n) << var << endl

//----------------------------------------------------------------

int main(void) {
  int a, b, c;
  cin >> a >> b >> c;

  if((c>a&&c<b)||(c>b&&c<a)){
    prt("Yes");
  } else {
    prt("No");
  }

}
