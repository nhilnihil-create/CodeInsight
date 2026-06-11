#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int A, B; cin >> A >> B; A--; B--;

  int H = 49, W = 98;
  char m[H][W]; rep(i, H) rep(j, W/2) { m[i][j]='#'; m[i][j+W/2]='.';}
  rep(i, A){
    int px = i/((W-2)/4), py = i%((W-2)/4); 
    m[2*px+1][2*py+1] = '.';
  }
  rep(i, B){
    int px = i/((W-2)/4), py = i%((W-2)/4); 
    m[2*px+1][2*py+1+W/2] = '#';
  }

  cout << H << " " << W << endl;
  rep(i, H) { rep(j, W) { cout << m[i][j]; } cout << endl; }
  return 0;
}