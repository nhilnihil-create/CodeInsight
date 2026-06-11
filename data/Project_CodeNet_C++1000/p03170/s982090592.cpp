#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e2 + 2, K = 1e5 + 5;
int numbers[N], n, dp[K][2];

int winner(int k, int turn) {
  if (K == 0)
    return !turn;

  if (dp[k][turn] != -1)
    return dp[k][turn];

  int currWinner = !turn;
  for (int i = 0; i < n && currWinner != turn && numbers[i] <= k; i++)
    currWinner = winner(k - numbers[i], !turn);

  return dp[k][turn] = currWinner;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(); cout.tie();
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> numbers[i];
  sort(numbers, numbers+n);
  for (int i = 0; i < K; i++)
    dp[i][0] = dp[i][1] = -1;
  
  if (winner(k, 0) == 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  
  return 0;
}
