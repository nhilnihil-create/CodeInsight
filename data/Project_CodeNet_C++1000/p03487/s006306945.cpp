#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> a;
  for(int i = 0; i < n; i++){
    int now;
    cin >> now;
    a[now]++;
  }
  
  int ans = 0;
  for(auto now : a){
    int dis = now.second - now.first;
    if(dis == 0) continue;
    if(dis < 0) ans += now.second;
    else ans += dis;
  }
  
  cout << ans << endl;
}