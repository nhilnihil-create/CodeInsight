#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
int main() {
  cout << fixed << setprecision(10);
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dx = -y2+y1;
  int dy = x2-x1;
  cout << x2+dx << " ";
  cout << y2+dy << " ";
  cout << x1+dx << " ";
  cout << y1+dy << endl;
}
