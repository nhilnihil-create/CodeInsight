#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int p;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    if(a.at(i) == 1) p = i;
  }
  
  int ans = (n-2) / (k-1) + 1;
  
  cout << ans << endl;
}