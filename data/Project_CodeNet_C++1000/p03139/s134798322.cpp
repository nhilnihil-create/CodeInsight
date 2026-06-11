#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,a,b;
  cin >>n >>a >>b;
  int ans1 = min(a,b);
  int ans2;
  if(a+b<n) ans2 = 0;
  else ans2 = a+b-n;
  cout << ans1 << " " << ans2 << endl;
  return 0;
}