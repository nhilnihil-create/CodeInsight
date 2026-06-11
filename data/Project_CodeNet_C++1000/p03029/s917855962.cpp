#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  int a, b;
  cin >> a >> b;
  int peace = a*3 +b;
  cout << peace / 2 << endl;
  return 0;
}