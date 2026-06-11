#include <bits/stdc++.h>
#define rep(i,n); for (int i = 0; i < n ;++i )
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int d = min(a*x + b*y,c*max(x,y)*2);
  int e;
  if(x<y){
    e = c*x*2 + b*(y-x);
  }
  else if(x>y){
    e = c*y*2 + a*(x-y); 
  }
  else{
    e = c*(x+y);
  }
  cout << min(d,e) << endl;
  return 0;
}
