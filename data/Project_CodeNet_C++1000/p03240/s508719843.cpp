#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> x(N), y(N), h(N);
  for (int i = 0; i < N; i++){
    cin >> x[i] >> y[i] >> h[i];
  }
  int s;
  for (int i = 0; i < N; i++){
    if (h[i] > 0){
      s = i;
      break;
    }
  }
  for (int i = 0; i <= 100; i++){
    for (int j = 0; j <= 100; j++){
      int H = h[s] + abs(y[s] - i) + abs(x[s] - j);
      bool ok = true;
      for (int k = 0; k < N; k++){
        if (h[k] != max(H - abs(y[k] - i) - abs(x[k] - j), 0)){
          ok = false;
        }
      }
      if (ok){
        cout << j << ' ' << i << ' ' << H << endl;
      }
    }
  }
}