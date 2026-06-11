#include <bits/stdc++.h>
#define v(T) vector<T>
#define yn {puts("Yes");}else{puts("No");}
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const double eps = 1e-10;

int main() {
  int a, b;
  cin >> a >> b;
  if (a * b % 2 == 0)
    puts("Even");
  else
    puts("Odd");
  return 0;
}
