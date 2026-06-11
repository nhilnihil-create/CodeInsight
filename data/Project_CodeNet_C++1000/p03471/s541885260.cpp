#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x,y,z, N, count=0, ans=0;
  ll Y;
    
  cin >> N >> Y;
  Y/=1000;
  
  for(x=0;x<N+1;x++){
    for(y=0;x+y<N+1;y++){
      z=N-x-y;
      if(x*10+y*5+z==Y) {
        cout << x << " " << y << " " << z;
        return 0;
      }
    }
  }
  
  cout << "-1 -1 -1";
}
  