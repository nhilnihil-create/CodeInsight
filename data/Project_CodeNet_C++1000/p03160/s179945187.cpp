#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int calcCost(int N, vector<int> heights) {

  // cout << "here\n";

  // init dp array
  vector<int> dp(N, 0);

  dp[0] = 0;
  dp[1] = abs(heights[1] - heights[0]);
  if (N == 2) {
    return dp[1];
  }

  int cost;
  int firstJump;
  int secondJump;
  for (int i = 2; i < N; i++) {
    firstJump = abs(heights[i]-heights[i-1]);
    secondJump = abs(heights[i]-heights[i-2]);
    cost = min(firstJump+dp[i-1], secondJump+dp[i-2]);
    dp[i] = cost;
  }
  return dp[N-1];
}

int main() {

  int numStones;
  int height;

  cin >> numStones;
  if (numStones < 2 || numStones > 100000) {
    cout << 0;
    return 0;
  }

  vector<int> heights(numStones + 1, -1);
  // cout << numStones << "\n";
  for (int i = 0; i < numStones; i++) {
    cin >> height;
    heights[i] = (int)height;
    // printf("enter\n");
    // heights.insert(heights.end(), height);
    // printf("exit\n");
  }

  // for (int i = 0; i < numStones; i++) {

  //   cout << heights[i];
  // }
  int cost = calcCost(numStones, heights);
  
  cout << cost;
  return 0;
}