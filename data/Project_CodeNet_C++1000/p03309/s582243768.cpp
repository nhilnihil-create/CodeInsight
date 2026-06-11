#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

void solve(){
  int n; cin >> n;
  vector<long long int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  for(int i = 0; i < n; i++){
    v[i] = v[i] - (i + 1);
  }
  sort(v.begin(), v.end());
  long long x = v[n / 2], y = v[n / 2 - 1], ansx = 0, ansy = 0;
  for(int i = 0; i < n; i++){
    ansx += abs(v[i] - x);
    ansy += abs(v[i] - y);
  }
  cout << min(ansx, ansy) << endl;
  return;
}
int main(){
  solve();
  return 0;
}
