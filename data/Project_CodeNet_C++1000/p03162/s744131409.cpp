#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int getPoints(int days, int input[days][3]) {

  // init 2d dp table - row is day number and
  // column is cumulative happiness for each day/activity
  int dp[days][3];

  // base case
  dp[0][0] = input[0][0];
  dp[0][1] = input[0][1];
  dp[0][2] = input[0][2];

  for (int i = 1; i < days; i++) {
    dp[i][0] = max((dp[i-1][1] + input[i][0]), 
                   (dp[i-1][2] + input[i][0]));
    dp[i][1] = max((dp[i-1][0] + input[i][1]), 
                   (dp[i-1][2] + input[i][1]));
    dp[i][2] = max((dp[i-1][0] + input[i][2]), 
                   (dp[i-1][1] + input[i][2]));
  }

  int maxPoints = -1;
  for (int i = 0; i < 3; i++) {
    maxPoints = max(maxPoints, dp[days-1][i]);
  }
  
  return maxPoints;
}

int main() {
  
  int numDays;
  cin >> numDays;

  int input[numDays][3];

  for (int i = 0; i < numDays; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> input[i][j];
    }
  }

  int happiness = getPoints(numDays, input);
  cout << happiness;

  return 0;
}