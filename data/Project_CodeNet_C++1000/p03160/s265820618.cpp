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
  int costTwoBefore = 0;
  int costOneBefore = abs(heights[1] - heights[0]);

  for(int i = 2; i < numStones; i++) {
      int temp = costOneBefore;
      costOneBefore = min(costOneBefore + abs(heights[i] - heights[i-1]),
                     costTwoBefore + abs(heights[i] - heights[i-2]));
      costTwoBefore = temp;
  }

  cout << costOneBefore;

  return 0;
}