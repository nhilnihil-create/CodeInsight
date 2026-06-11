#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, K;
  cin >> N >> K;
  long long count = 0;
  for(int i = 1; i <= N; i++){
    long long j = K - i % K;
    long long b = (N - j) / K + 1;
    if((j + j) % K == 0){
      count += b * b;
    }
  }
  cout << count <<endl;
}
