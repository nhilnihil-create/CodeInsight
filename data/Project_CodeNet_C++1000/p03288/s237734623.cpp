#include <bits/stdc++.h>
#include <math.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;
const int mINF = -1001001001;


int main() {
int r;
cin >> r;
if(r<1200) {
  cout << "ABC" << endl;
} else if(1200<=r&&r<2800) {
  cout << "ARC" << endl;
} else {
  cout << "AGC" << endl;
}
return 0;
}
