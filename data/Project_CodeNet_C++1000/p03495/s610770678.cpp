#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool bigorder(const int& a, const int& b)
{
  return a > b;
}
int main()
{
  int K, N;
  cin >> N >> K;
  vector <int> A(N+1);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[a]++;
  }
  sort(A.begin(), A.end(), bigorder);
  int ans = 0;
  for (int i = K; i <= N; i++) {
    ans += A[i];
  }
  cout << ans << endl;
  return 0;
}
