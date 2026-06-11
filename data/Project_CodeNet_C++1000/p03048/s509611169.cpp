#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map> 
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)



int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int res = 0;
  for (int i = 0;i <= n;i++){
     for (int j = 0; j <= n;j++){
        if ((n-i*r - g*j) >= 0 && (n-i*r - g*j)%b == 0) {
           res++;
           //printf("(i,j,k) = (%d,%d,%d)\n",i,j,(n-i*r - g*j)/b); 
        } 
     }
  }
  cout << res << endl;

   return 0;
}

