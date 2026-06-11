#include<iostream>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  int max_gcd = 0;
  for (int i = 1; i <= M / i; i++) {
    if (M % i == 0) {
      if (i >= N) max_gcd = max(max_gcd, M/i);
      if (M/i >= N) max_gcd = max(max_gcd, i);
    }
  }
  cout<<max_gcd<<endl;
}