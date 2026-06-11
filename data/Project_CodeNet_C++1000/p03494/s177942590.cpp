#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  int ans = INT_MAX;
  auto chmin = [&](int &a, int b){
    if(a > b){a = b;}
  };
  for(int i = 0; i < n; i++){
    int p; cin >> p;
    int cnt = 0;
    while(p % 2 == 0){
      cnt++;
      p /= 2;
    }
    chmin(ans, cnt);
  }
  cout << ans << endl;
}