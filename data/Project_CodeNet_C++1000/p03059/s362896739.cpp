#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  int a, b, t;
  cin >> a >> b >> t;

  int num = t/a;
  int ans = num * b;
  cout << ans << endl;

}