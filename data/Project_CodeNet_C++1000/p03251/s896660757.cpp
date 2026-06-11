
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
int n,m,x,y;
cin >> n >> m >> x >> y;
int xn[n],ym[m];
int x_max=mINF,y_min=INF;
REP(i,n) {
  cin >> xn[i];
  x_max = max(x_max,xn[i]);
}
REP(i,m) {
  cin >> ym[i];
  y_min = min(y_min,ym[i]);
}
int flg=-1;
if(x_max<y_min) {
  for(int i=x_max+1;i<=y_min;i++) {
    if(x<i&&i<=y) flg++;
  }
}
if(flg!=-1){cout << "No War" << endl;}else{
cout << "War" << endl;}

return 0;
}
