#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N, M;
  cin >> N >> M;
  map<int, int> likeCounts;
  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int A;
      cin >> A;
      likeCounts[A]++;
    }
  }

  int ans = 0;
  for (auto count : likeCounts) {
    if(count.second==N) ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}
