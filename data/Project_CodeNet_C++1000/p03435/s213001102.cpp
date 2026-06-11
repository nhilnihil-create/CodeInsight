#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll N[3][3];
  rep(i,3){
    rep(j,3){
      cin >> N[i][j];
    }
  }
  bool a = true;
  if(N[0][0]-N[0][1] != N[1][0]-N[1][1]){a=false;}
  if(N[0][0]-N[1][0] != N[0][1]-N[1][1]){a=false;}
  if(N[1][0]-N[1][1] != N[2][0]-N[2][1]){a=false;}
  if(N[1][0]-N[2][0] != N[1][1]-N[2][1]){a=false;}
  if(N[0][1]-N[0][2] != N[1][1]-N[1][2]){a=false;}
  if(N[0][1]-N[1][1] != N[0][2]-N[1][2]){a=false;}
  if(N[1][1]-N[1][2] != N[2][1]-N[2][2]){a=false;}
  if(N[1][1]-N[2][1] != N[1][2]-N[2][2]){a=false;}
  
  if(a){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}