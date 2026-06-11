#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  vector<int> num(N);
  for (int i = 0; i < N; i++) {
    cin >> num.at(i);
  }
  
  sort(num.begin(), num.end());
  
  vector<int> a(N);
  
  int count = 0;
  int check = num.at(0);
  
  for(int i = 0; i < N; i++) {
    if (num.at(i) == check) {
      count++;
      if (i == N - 1) {
        a.at(i) = count;
      }
    }
    else {
      a.at(i) = count;
      count = 1;
      if (i == N - 1) {
        a.at(0) = count;
      }
      check = num.at(i);
    }
  }
  
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  
  int ans = 0;
  
  for (int i = K; i < N; i++) {
    ans += a.at(i);
  }
  
  cout << ans << endl;
  
}