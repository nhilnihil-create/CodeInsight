#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; //餅の枚数
  cin >> n;
  vector<int> rice(n,0);
  
  
  for(int i = 0;i < n;i++){
      cin >> rice.at(i);
  }
  
  int ans = 1;
  
  sort(rice.begin(),rice.end());
  for(int i = 0;i < n -1;i++){
      if(rice.at(i) < rice.at(i + 1)){
          ans++;
      }
  }
  cout << ans << endl;
}
