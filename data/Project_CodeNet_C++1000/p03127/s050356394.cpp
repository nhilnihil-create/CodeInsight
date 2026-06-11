#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  int64_t GCD = __gcd(A[0], A[1]);
  for (int i = 0; i < N; i++)
  {
    GCD = __gcd(GCD, A[i]);
  }
  cout << GCD << endl;
}
