#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  vector<double> temp(n);
  for (int i=0 ; i<n ; i++){
    cin >> h.at(i);
    temp.at(i) = t - h.at(i)*0.006;
  }
  
  double min = abs(temp.at(0) - a);
  int ans = 1;
  for (int i=1 ; i<n ; i++){
    if (abs(temp.at(i) - a) < min){
      min = abs(temp.at(i) - a);
      ans = i+1;
    }
  }
  
  cout << ans << endl;
}