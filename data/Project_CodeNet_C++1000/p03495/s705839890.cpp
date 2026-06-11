#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K,N;
  cin >> N >> K;
  
  vector<int>A(N);
  vector<int>B(N,0);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    B.at(A.at(i)-1)++;
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  
  int count0 = 0;
  for (int i = 0; i < N; i++) {
    if (B.at(i) == 0){
      count0++;
    }
  }
  int M = N - count0 - K;
  
  int count1 = 0;
  reverse(B.begin(), B.end());
  for (int i = count0; i < count0+M; i++) {
    count1 += B.at(i);
  }
  cout << count1 << endl;
}
  
      