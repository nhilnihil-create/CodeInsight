#include <iostream>
#include <vector>
#include <bitset>

std::bitset<2000010> dp;

using namespace std;

int main()
{
  int N;
  cin >> N;
  
  vector<int> A;
  int a,sum = 0;
  for (int i = 0; i < N; i++) {
      cin >> a;
      A.push_back(a);
      sum += a;
  }
  
  dp[0] = true;
  for (int i = 0; i < N; i++) {
      dp |= dp << A[i];
  }
  
  int ans;
  for (int k = sum / 2; k >= 0; k--) {
      if (dp[k]) {
          ans = k;
          break;
      }
  }
  
  cout << sum - ans << endl;
  return 0;  
}
