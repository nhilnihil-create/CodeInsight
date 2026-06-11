#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,ans = 1,d = 1;
  cin >> n;
  int dc = 0;
  rep(i,n){
    int a;
    cin >> a;
    if(a%2 == 0) dc++;
  }
  rep(i,n) ans *= 3;
  rep(i,dc) d *= 2;
  cout << ans-d << endl;
}