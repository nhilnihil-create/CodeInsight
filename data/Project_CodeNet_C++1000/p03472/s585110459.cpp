#include <bits/stdc++.h>
using namespace std;

int main () {
  long long N,H;
  cin >> N >> H;
  
  vector<long long>a(N);
  vector<long long>b(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i) >> b.at(i);
  }
  
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  long long A = a.at(0);
  
  long long countb = 0;
  long long sumB = 0;
  for (int i = 0; i < N; i++) {
    if (b.at(i) > A){
      countb++;
      sumB += b.at(i);
      if (sumB >= H){
        cout << countb << endl;
        return 0;
      }
    }
    else {
      break;
    }
  }
  cout << (H - sumB + A - 1)/A + countb << endl;
}
  
  
  
 
  
   