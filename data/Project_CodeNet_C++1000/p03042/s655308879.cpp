#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)


int main() {
  int s;
  cin >> s;
  int l = s/100;
  int r = s%100;
  int lb = (0<l && l<13)?1:0;
  int rb = (0<r && r<13)?1:0;
  if (lb && rb) cout << "AMBIGUOUS" << endl;
  else if (lb) cout << "MMYY" << endl;
  else if (rb) cout << "YYMM" << endl;
  else cout << "NA" << endl;
  return 0;
}