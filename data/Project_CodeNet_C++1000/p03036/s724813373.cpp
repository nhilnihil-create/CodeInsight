#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int r, D, this_year;
  cin >> r >> D >> this_year;
  
  int cnt = 10;
  int next_year;
  while(cnt--) {
  	next_year = r * this_year - D;
    cout << next_year << endl;
    this_year = next_year;
  }
  return 0;
}
