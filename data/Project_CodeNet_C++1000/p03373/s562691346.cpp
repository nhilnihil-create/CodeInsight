#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(int i = 1; i <= (int)(n); i++)

const long long INF = 1LL << 60;

int main() {
  int a,b,c,x,y,res=10000000000;
  cin >> a >> b >> c >> x >> y;
  
  rep(i,100001){
    res=min(res,i*c*2+max(0,x-i)*a+max(0,y-i)*b);
  }
  
  cout << res << endl;
}