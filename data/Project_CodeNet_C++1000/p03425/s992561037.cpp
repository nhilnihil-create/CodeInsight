#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
string S[100000];

int main(int argc, char* argv[]) {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  long long int nums[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < N; i++) {
    switch (S[i][0]) {
      case 'M':
        nums[0]++;
        break;
      case 'A':
        nums[1]++;
        break;
      case 'R':
        nums[2]++;
        break;
      case 'C':
        nums[3]++;
        break;
      case 'H':
        nums[4]++;
        break;
    }
  }

  long long int res = 0;
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
      for (int k = j + 1; k < 5; k++)
        res += nums[i] * nums[j] * nums[k];

  cout << res << endl;
  return 0;
}