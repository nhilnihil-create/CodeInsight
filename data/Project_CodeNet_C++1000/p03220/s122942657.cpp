#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  double min = 1e9, ans = 0;
  int min_index = 0;
  for(int i = 0; i < n; i++){
    ans = abs((t - h[i] * 0.006) - a);
    if(ans < min){
      min = ans;
      min_index = i + 1;
    }
  }
  cout << min_index << endl;
  return 0;
}