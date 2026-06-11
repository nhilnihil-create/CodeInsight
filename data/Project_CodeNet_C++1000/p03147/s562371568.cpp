#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> h(N),height(N,0);
  for(int i=0;i<N;i++) cin >> h.at(i);
  int ans = 0;
  while(1){
    int ans_tmp = ans;
    for(int i=0;i<N;i++){
      if(height.at(i) != h.at(i) ){
        for(int j=i;j<N;j++){
          if(height.at(j) != h.at(j) ) height.at(j) ++;
          else break;
        }
        ans ++;
        i = -1;
      }
    }
//    cout << ans << endl;
//    for(int k=0;k<N;k++) cout << height.at(k) << endl;
    if(ans == ans_tmp) break;
  }
  
//  for(int i=0;i<N;i++) cout << height.at(i) << endl;
  cout << ans << endl;
}