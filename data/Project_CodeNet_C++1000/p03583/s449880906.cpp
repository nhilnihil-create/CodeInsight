#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  int n = 0;
  cin >> n;
  int a,b,c;
  a = 0;
  b = 0;
  c = 0;
  for(int i = 1;i <= 3500;i++){
    for(int j = 1;j <= 3500;j++){
      if(4 * i * j != j * n + i * n){
        ll x,y;
        x = 1ll * i * j * n;
        y = 4 * i * j - j * n - i * n;
        if(x % y == 0 && y > 0 && x / y > 0 && x / y <= 3500){
          c = x / y;
          a = i,b = j;
          i = 3501,j = 3501;
        }
        //cout << i << " " << j << endl;
      }
    }
  }
  cout << a << " " << b << " " << c << endl;
}