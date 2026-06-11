#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  int64_t answer = 0;
  int64_t before_two = 0;
  int64_t before_one = 0;
  for (int i = 0; i < N; i++) {
	if (i == 0) {
      answer = 1;
      before_one = 1;
      before_two = 2;
    } else {
      answer = before_one + before_two;
      before_two = before_one;
      before_one = answer;
    }
  }
  cout << answer << endl;
  
}
