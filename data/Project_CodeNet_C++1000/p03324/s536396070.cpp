#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  long long d,n;
  cin >> d >> n;
  if(n==100){
    n=101;
  }
  int x = pow(100,d);
  cout << x*n << endl;
  
}