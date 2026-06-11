#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
ll x,y;
cin >> x >> y;
if(x==0||y==0) cout << 0 << endl;
else{
  int cnt = 0;
  while(x<=y){
    cnt++;
    x *= 2;
  }
  cout << cnt << endl;
}
}
