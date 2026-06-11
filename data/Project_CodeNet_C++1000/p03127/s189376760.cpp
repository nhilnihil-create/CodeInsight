#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  REP2(i,1,n){
    a[i] = __gcd(a[i],a[i-1]);
  }

  cout << a[n-1] << endl;
  return 0;
}
