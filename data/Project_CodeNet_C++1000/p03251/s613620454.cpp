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
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  vector<int> a(n);
  vector<int> b(m);
  rep(i,n) cin >> a.at(i);
  rep(i,m) cin >> b.at(i);
  int amax = x;
  int bmin = y;
  rep(i,n){
    amax = max(amax,a.at(i));
  }
  rep(i,m){
    bmin = min(bmin,b.at(i));
  }
  if(bmin>amax){
    cout << "No War" << endl;
  }else{
    cout << "War" << endl;
  }
}
