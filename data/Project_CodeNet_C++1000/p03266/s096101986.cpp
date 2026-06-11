#include <iostream>
using namespace std;
int main(void) {
  long long N, K;
  cin >> N >> K;
  long long ans = 0;
  if (K%2==1) {
    ans = (N/K)*(N/K)*(N/K);
  } else {
     long long ans1 = (N/K)*(N/K)*(N/K);
     long long ans2 = 0;
     for (int a = 1; a <= N; a++) {
       if (a%K==(K/2)) ans2++;
     }
     ans2 = ans2*ans2*ans2;
     ans = ans1+ans2;
  }
  cout << ans << endl;
  return 0;
}
