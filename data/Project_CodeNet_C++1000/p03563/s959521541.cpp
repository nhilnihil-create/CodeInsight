#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 
#define sqrt(d) pow((long double) (d), 0.50)

const ll INF = 2e9;
const ll large_P = 1e9 + 7;


int main(){
  int R, G;
  cin >> R >> G;
  
  cout << 2*G - R << endl;
  
}