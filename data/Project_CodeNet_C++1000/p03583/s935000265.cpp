#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  for(lint h = 1; h <= 3500; h++){
    for(lint n = 1; n <= 3500; n++){
      lint x = N * h * n;
      lint y = 4 * h * n - N * n - N * h;
      if(y > 0 && x % y == 0){
        lint w = x / y;
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }
}