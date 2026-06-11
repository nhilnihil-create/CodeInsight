#include <bits/stdc++.h>
using namespace std;

void chmin(int& a, int b) {
  if (a > b) a = b;
}

int main() {
  int N, K;
  cin >> N >> K;
  
  int ans = 1000000;
  int num;
  for (int i = 1; i <= N; i++) {
    num = ((i + K-3)/ (K-1)) + ((N - i + (K-2))/(K-1));
    
    chmin(ans, num);
   
  }
    cout << ans << endl;
  
}


