#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define SUM(a)  accumulate((a).begin(),(a).end(),0)
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
typedef long long ll;
const int INTINF = 1<<29;
const ll LLINF = 1LL<<61;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int DX[8]={ 0, 1, 0,-1, 1, 1,-1,-1};
const int DY[8]={ 1, 0,-1, 0, 1,-1, 1,-1};

double dist(pair<int,int> a, pair<int,int> b){
  return pow((pow((a.first - b.first),2) + pow((a.second - b.second),2)),0.5);
 
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c;
  cin >> a >> b >> c;
  cout << b + min(a+b+1,c) << endl;
}
