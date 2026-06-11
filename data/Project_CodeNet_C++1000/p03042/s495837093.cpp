#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  int f,l;
  f = n / 100;
  l = n % 100;
  if((f > 12 || f == 0) && (l > 12 || l == 0)) cout << "NA" << endl;
  if((f <= 12 && f != 0) && (l > 12 || l == 0)) cout << "MMYY" << endl;
  if((f <= 12 && f != 0) && (l <= 12 && l != 0)) cout << "AMBIGUOUS" <<  endl;
  if((f > 12 || f == 0) && (l <= 12 && l != 0)) cout << "YYMM" << endl;
}