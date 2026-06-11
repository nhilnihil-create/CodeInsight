#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int s;
  cin >> s;
  
  int a = s/100;
  int b = s%100;
  
  int c = 0;
  if (b == 0 || b > 12) c += 1;
  if (a == 0 || a > 12) c += 2;
  
  if (c == 0) cout << "AMBIGUOUS" << endl;
  if (c == 1) cout << "MMYY" << endl;
  if (c == 2) cout << "YYMM" << endl;
  if (c == 3) cout << "NA" << endl;
  
}