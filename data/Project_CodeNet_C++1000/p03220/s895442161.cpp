#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  double th;
  double closest = 1000000;
  int ans = 0;
  for(int i=0; i<n; i++) {
    cin >> h.at(i);
    th = t - h.at(i)*0.006;
    double temp = (a-th) * (a-th);
    if(temp < closest) {
      ans = i+1;
      closest = temp;
    }
  }
  cout << ans << endl;
  }
  