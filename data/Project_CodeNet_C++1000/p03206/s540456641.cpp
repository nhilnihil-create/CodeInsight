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
int x,y;
cin >> x;
if(x==25) {
  cout << "Christmas" << endl;
} else if(x==24) {
  cout << "Christmas Eve" << endl;
} else if(x==23) {
  cout << "Christmas Eve Eve" << endl;
} else {
  cout << "Christmas Eve Eve Eve" << endl;
}
return 0;
}
