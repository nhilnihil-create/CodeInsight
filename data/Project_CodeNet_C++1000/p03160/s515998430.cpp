#include <iostream>
#include <vector>
using namespace std;

int main() {
  
  int numStones;
  cin >> numStones;
  vector<int> heights(numStones);
  for(int& height : heights) {
      cin >> height;
  }
  vector<int> costs(numStones, 0);
  costs[1] = abs(heights[1] - heights[0]);

  for(int i = 2; i < costs.size(); i++) {
      costs[i] = min(costs[i-1] + abs(heights[i] - heights[i-1]),
                     costs[i-2] + abs(heights[i] - heights[i-2]));
  }

  cout << costs[costs.size()-1];

  return 0;
}