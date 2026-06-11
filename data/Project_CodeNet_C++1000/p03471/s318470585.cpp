#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  ll yen;
  cin >> n >> yen;

  for(int x = 0; x <= n; x++){
    for(int y = 0; y <= n-x; y++){
      int z = n - x - y;
      if(10000*x+5000*y+1000*z==yen){
        printf("%d %d %d",x,y,z);
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;

  return 0;
}
