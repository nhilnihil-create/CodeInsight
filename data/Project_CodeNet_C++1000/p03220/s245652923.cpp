#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double t, a;
  cin >> n >> t >> a;
  double min_value = 100000;
  int min_index = -1;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < n; i++){
    double diff = abs((t - h[i] * 0.006) - a);
    if(diff < min_value){
      min_value = diff;
      min_index = i + 1;
    }
  }
  cout << min_index << endl;
  return 0;
}