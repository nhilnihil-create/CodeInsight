#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x;
  cin >> N >> x;
  vector<int>a(N);
  for(int i=0; i<N; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  
  int ans =0;
  for(int i=0; i<N; i++){
    x -= a.at(i);
    
    if(x>=0) ans ++;
    else break;
  }
  
  if(x>0)ans --;
  
  cout << ans << endl;
  
}