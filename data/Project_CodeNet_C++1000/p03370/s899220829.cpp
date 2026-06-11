#include<iostream>
using namespace std;
int main(){
  int n,x; cin >> n >> x;
  int min_m = 99999;
  for(int i = 0; i < n; i++){
    int m; cin >> m;
    x -= m;
    min_m = min(min_m,m);
  }
  int ans = n;
  if(x >=0)
    ans += x/ min_m;
  
  cout << ans ;
}