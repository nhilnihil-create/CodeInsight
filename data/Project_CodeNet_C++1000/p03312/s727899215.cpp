#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<long long int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  vector<long long int> bestL1(N, -1), bestL2(N, -1);
  long long int ct = 0;
  bestL1[1] = A[0];
  bestL2[1] = A[1];
  for (int i = 2; i < N; i++) {
    bestL1[i] = bestL1[i - 1];
    bestL2[i] = bestL2[i - 1] + A[i];
    while (abs(bestL1[i] + 2 * A[ct + 1] - bestL2[i]) < abs(bestL1[i] - bestL2[i])) {
      bestL1[i] += A[ct + 1];
      bestL2[i] -= A[ct + 1];
      ct++;
    }
  }
  
  vector<long long int> bestR1(N, -1), bestR2(N, -1);
  ct = N - 1;
  bestR1[N - 2] = A[N - 1];
  bestR2[N - 2] = A[N - 2];
  for (int i = N - 3; i >= 0; i--) {
    bestR1[i] = bestR1[i + 1];
    bestR2[i] = bestR2[i + 1] + A[i];
    while (abs(bestR1[i] + 2 * A[ct - 1] - bestR2[i]) < abs(bestR1[i] - bestR2[i])) {
      bestR1[i] += A[ct - 1];
      bestR2[i] -= A[ct - 1];
      ct--;
    }
  }
  
  long long int ans = 4000000000;
  for (int i = 1; i < N - 2; i++) {
    long long int ansMax = max(bestL1[i], bestL2[i]);
    ansMax = max(ansMax, bestR1[i + 1]);
    ansMax = max(ansMax, bestR2[i + 1]);
    
    long long int ansMin = min(bestL1[i], bestL2[i]);
    ansMin = min(ansMin, bestR1[i + 1]);
    ansMin = min(ansMin, bestR2[i + 1]);
    
    ans = min(ans, ansMax - ansMin);
  }
  
  cout << ans << endl;

  return 0;
}