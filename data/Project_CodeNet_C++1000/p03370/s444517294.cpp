#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  int sum = 0, mini = 10000;
  for(int i = 0; i < n; i++){
    cin >> m[i];
    sum += m[i];
  }
  for(int i = 0; i < n; i++){
    if(m[i] < mini) mini = m[i];
  }
  int ans = n + (x - sum) / mini;
  
  cout << ans << endl;
  return 0;
}