#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H;
  cin >> N >> H;
  
  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  


  
  // aの攻撃はa[N-1]，bの攻撃はa[N-1]より大きいものに限って大きい順に使う
  
  int damage = 0;
  int count = 0;
  
  for (int i = N-1; i >= 0; i--){
    if (b[i] < a[N-1]) break;
    damage += b[i];
    count++;
    if (damage >= H) {
      cout << count << endl;
      return 0;
    }
  } 
  
  count += (H-damage + a[N-1] - 1) / a[N-1];
  
  cout << count << endl;


}