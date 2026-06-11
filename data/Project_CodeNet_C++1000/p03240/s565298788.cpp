#include<bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  vector<lint> x(N), y(N), h(N);
  lint px, py, ph;
  for(lint i = 0; i < N; i++){
    cin >> x[i] >> y[i] >> h[i];
    if(h[i] != 0){
      px = x[i]; py = y[i]; ph = h[i];
    } 
  }
  for(lint i = 0; i <= 100; i++){
    for(lint j = 0; j <= 100; j++){
      lint height = ph + abs(px - i) + abs(py - j);
      bool ok = true;
      for(lint k = 0; k < N; k++){
        if(max(height - abs(x[k] - i) - abs(y[k] - j), lint(0)) != h[k]) ok = false;
      }
      if(ok){
        cout << i << " " << j << " " << height << endl;
        return 0;
      }
    }
  }
}
