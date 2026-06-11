#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n; cin >> n;
  int a[2][n];
  for(int i=0; i<2; ++i) for(int j=0; j<n; ++j) cin >> a[i][j];

  for(int i=0; i<2; ++i){
    for(int j=0; j<n; ++j){
      if(i==0 && j==0) continue;
      if(i==0 && j>0){
        a[i][j] += a[i][j-1];
      }
      else if(i==1 && j==0){
        a[i][j] += a[0][0];
      }
      else{
        a[i][j] = max(a[i-1][j], a[i][j-1]) + a[i][j];
      }
    }
  }
  cout << a[1][n-1] << endl;

}