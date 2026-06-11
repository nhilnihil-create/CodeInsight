#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int s;
  cin >> s;
  vector<long long int> vec(1000000, 1000000);
  vec.at(0) = s;
  bool finished = false;
  for(long long int i = 1; i < 1000000; i++) {
    if(vec.at(i - 1) % 2 == 0) {
      vec.at(i) = vec.at(i - 1) / 2;
    }
    else {
      vec.at(i) = vec.at(i - 1) * 3 + 1;
    }
    for(long long int j = 0; j < i; j++) {
      if(vec.at(j) == vec.at(i)) {
        cout << i + 1 << endl;
        finished = true;
        break;
      }
    }
    if(finished) {
      break;
    }
  }
}