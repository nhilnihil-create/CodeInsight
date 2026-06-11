# include <stdio.h>
# include <string.h>
# include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 5e5 + 10;
const int mod = 1e9 + 7;

int n, a, b; 

int main() {
  std :: ios :: sync_with_stdio(false); 
  std :: cin.tie(0); 
  std :: cout.tie(0);
  ll sum = 0;
  int mi = 2e9;
  bool flag = 1;
  cin >> n;
  for (int i = 1; i <= n; ++ i) {
    cin >> a >> b;
    flag &= (a == b);
    sum += a;
    if(a > b) mi = min(mi, b);
  }
  if(flag) puts("0");
  else cout << sum - mi << endl;
  return 0;
}


