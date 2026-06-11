#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, T, A; // Tは元の気温　A はターゲット
  cin >> N >> T >> A;
  vector<float> temp(N);
  for (int i = 0; i < N ; i++){
    cin >> temp.at(i);
    temp.at(i) = T - 0.006*temp.at(i); //高さを温度に変換
    temp.at(i) = fabsf(A - temp.at(i));// 温度をAとの差に変換
  }
//  cout << temp.at(0) << "  " << temp.at(1) << endl;
  int ans = 0;
  float tempAns =temp.at(0);
  for (int i=1; i < N; i++){
    if (tempAns > temp.at(i)){
      ans = i;
      tempAns = temp.at(i);
    }
  }
  
  cout << ans+1 << endl;  
}
