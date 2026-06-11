#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int a, b, d, h;
  cin >> a >> b;
  d = (b - a);
  h = d * (d + 1) / 2;
  cout << h - b << endl;
  return 0;
}