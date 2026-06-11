#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  long long ans = 0;
  cin >> N;
  vector<int> A(N, 0), B(N, 0), C(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> B.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> C.at(i);
  }
  vector<int>::iterator itrB = B.end(), itrC = C.end();
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  for (int i = 0; i < N; i++)
  {
    itrB = lower_bound(A.begin(), A.end(), B[i]);
    itrC = upper_bound(C.begin(), C.end(), B[i]);
    ans += distance(A.begin(), itrB) * distance(itrC, C.end());
  }
  cout << ans << endl;
  return 0;
}