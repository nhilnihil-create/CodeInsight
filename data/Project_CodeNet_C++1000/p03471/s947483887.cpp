#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, y;
  cin >> n >> y;
  int cnt_10000 = -1, cnt_5000 = -1, cnt_1000 = -1;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j + i <= n; j++){
      int k = n - i - j;
      int ans = 10000 * i + 5000 * j + 1000 * k;
      if(ans == y){
        cnt_10000 = i;
        cnt_5000 = j;
        cnt_1000 = k;
      }
    }
  }
  cout << cnt_10000 << " " << cnt_5000 << " " << cnt_1000 << endl;
  return 0;
}