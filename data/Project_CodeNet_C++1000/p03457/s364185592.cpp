#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int i;
  vector<int> t(2, 0);
  vector<int> x(2, 0);
  vector<int> y(2, 0);
  for(i = 0; i < n; i++){
    cin >> t[1] >> x[1] >> y[1];
    int d_t = t[1] - t[0];
    int d_x = abs(x[1] - x[0]);
    int d_y = abs(y[1] - y[0]);
    int a = d_t - (d_x + d_y);
    if(a >= 0 && a%2 == 0){
      t[0] = t[1];
      x[0] = x[1];
      y[0] = y[1];
    }else{break;}
  }
  if(i == n){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
