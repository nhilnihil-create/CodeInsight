#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int d,n;
  cin >>d >>n;
  if(n==100) n++;
  int ans = 100*n;
  for(int i = 1; i<d; i++){
    ans *= 100;
  }
  if(d==0) ans = n;
  cout << ans << endl;
  return 0;
}