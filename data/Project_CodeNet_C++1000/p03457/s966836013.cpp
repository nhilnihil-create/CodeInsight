#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int t=0, x=0, y=0;
  bool ans = true;
  for(int i=0; i<n; ++i){
    int nt, nx, ny;
    cin >> nt >> nx >> ny;
    if((nt-t)%2 != abs((x+y)-(nx+ny))%2) ans = false;
    if((nt-t) < (abs(x-nx)+abs(y-ny))) ans = false;
    if(!ans){
      cout << "No" << endl;
      return 0;
    }
    t = nt; x = nx; y = ny;
  }
  cout << "Yes" << endl;
}