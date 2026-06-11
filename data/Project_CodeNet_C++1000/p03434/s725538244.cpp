#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums.at(i);
  }
  
  sort(nums.begin(), nums.end());
  reverse(nums.begin(), nums.end());
  
  int answer = 0;
  for (int i = 0; i < N; i++) {
    if ((i + 1) % 2 != 0) {
      answer += nums.at(i);
    } 
    else {
      answer -= nums.at(i);
    }
  }
  
  cout << answer << endl;
}
