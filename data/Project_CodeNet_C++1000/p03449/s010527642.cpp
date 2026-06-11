#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int N, nums[2][100];

  cin >> N;
  for(int i = 0; i < 2; i++) for (int j = 0; j < N; j++) cin >> nums[i][j];

  for (int i = 1; i < N; i++) nums[0][i] += nums[0][i - 1];
  nums[1][0] += nums[0][0];
  for (int i = 1; i < N; i++) nums[1][i] += max(nums[1][i - 1], nums[0][i]);
  cout << nums[1][N - 1] << endl;
  return 0;
}
