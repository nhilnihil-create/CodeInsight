#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  int sum = 0, min = 1001001001;
  for(int i = 0; i < n; i++){
    cin >> m[i];
    sum += m[i];
    if(m[i] < min){
      min = m[i];
    }
  }
  int ans = n + (x - sum) / min;
  cout << ans << endl;
  
  return 0;
}