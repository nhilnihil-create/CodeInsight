#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> A(N+2);
  for (int i = 1; i <= N; i++) cin >> A[i];

  vector<int> cs(N+2);
  for (int i = 1; i <= N+1; i++)
    cs[i] = cs[i-1] + abs(A[i]-A[i-1]);

  for (int i = 1; i <= N; i++) {
    cout << cs[i-1] + (cs.back()-cs[i+1]) + abs(A[i+1]-A[i-1]);
    cout << "\n";
  }
}