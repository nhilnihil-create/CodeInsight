#include <bits/stdc++.h>
using namespace std;

int main() {
  double n;
  cin >> n;
  vector<double> a(n);
  double sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  double k = sum / n;
  double dis = -10000;
  int ans = -1;
  for(int i = 0; i < n; i++){
    double now = abs(k - a.at(i)), old = abs(k - dis);
    if(now < old) ans = i, dis = a.at(i);
  }
  
  cout << ans << endl;
}