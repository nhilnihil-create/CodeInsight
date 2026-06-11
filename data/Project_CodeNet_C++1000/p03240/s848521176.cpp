#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  vector<int> h(N);
  for (int i = 0; i < N; i++) cin >> x.at(i) >> y.at(i) >> h.at(i);
  
  for (int Cx = 0; Cx <= 100; Cx++){
    for (int Cy = 0; Cy <= 100; Cy++){
      int H = 0;
      for (int i = 0; i < N; i++){
        if (h.at(i) > 0){
          H = h.at(i) + abs(x.at(i) - Cx) + abs(y.at(i) - Cy);
          break;
        }
      }
      
      bool flag = true;
      for (int i = 0; i < N; i++){
        if (h.at(i) == max(H - abs(x.at(i) - Cx) - abs(y.at(i) - Cy), 0)){
          continue;
        }
        else{
          flag = false;
          break;
        }
      }
      
      if (flag){
        cout << Cx << " " << Cy << " " << H << endl;
        return 0;
      }
    }
  }   
}