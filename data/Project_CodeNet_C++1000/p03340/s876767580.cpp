#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A.at(i);

  long long res = 0, sum = 0, right = 0;
  for (int left = 0; left < N; ++left) {
    while (right < N && ((sum + A[right]) == (sum ^ A[right]))) {
      sum += A[right];
      ++right;
    }
    res += (right - left);
    if (right == left) ++right;
    else sum -= A[left];
  }
  cout << res << endl;
  return 0;
}
