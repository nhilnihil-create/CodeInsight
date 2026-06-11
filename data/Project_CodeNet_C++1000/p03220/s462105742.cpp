#include<bits/stdc++.h>
using namespace std;

int main(){
  double n,t,a;
  cin >> n >> t >> a;
  int ans1;
  double ans;
  vector<double> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
    h[i] = t - h[i] * 0.006;
  }
  ans = abs(h[0] - a);
  ans1 = 1;
  for(int i = 1; i < n; i++){
    ans = min(ans, abs(h[i] - a));
    if(ans == abs(h[i] - a)) ans1 = i + 1;
  }
  cout << ans1 << endl;
}