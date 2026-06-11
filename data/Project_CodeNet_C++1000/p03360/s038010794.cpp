#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  int ans = a + b + c;
  int d = max((a,b),c);
  ans -= d;
  int i = 1;
  while(i <= k){
    d *= 2;
    ++i;
  }
  cout << d + ans << endl;
}