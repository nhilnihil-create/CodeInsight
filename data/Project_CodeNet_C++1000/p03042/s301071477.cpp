#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int s, a, b;
  cin >> s;
  a = s / 100;
  b = s % 100;
  string ans;
  if(1<=a && a<=12 && 1<=b && b<=12) ans ="AMBIGUOUS";
  else if(0<=a && a<=99 && 1<=b && b<=12) ans ="YYMM";
  else if(1<=a && a<=12 && 0<=b && b<=99) ans ="MMYY";
  else ans ="NA";
  cout << ans << endl;
}
