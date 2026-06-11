#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector <int> A(N+2); // position
  vector <int> sum_cost(N+2);
  A[0] = 0;
  sum_cost[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    sum_cost[i] = sum_cost[i-1] + abs(A[i]-A[i-1]);
  }
  A[N+1] = 0;
  sum_cost[N+1] = sum_cost[N] + abs(A[N+1]-A[N]);
  
  for (int i = 1; i <= N; i++) {
    int ans = sum_cost[i-1];
    ans += (sum_cost[N+1] - sum_cost[i+1]);
    ans += abs(A[i+1]-A[i-1]);
    cout << ans << endl;
  }
  return 0;
}
