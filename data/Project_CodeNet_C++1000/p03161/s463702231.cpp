#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
  
  int numStones;
  cin >> numStones;
  int K;
  cin >> K;
  vector<int> heights(numStones);
  for(int& height : heights) {
      cin >> height;
  }
  vector<int> costs(numStones, INT_MAX);
  costs[0] = 0;

  for(int i = 1; i < costs.size(); i++) {
  	int step = K;
  	for(int j = i-1; j >= 0 && step > 0; j--, step--) {
      costs[i] = min(costs[i], costs[j] + abs(heights[i] - heights[j]));
    }
  }

  cout << costs[costs.size()-1];

  return 0;
}
