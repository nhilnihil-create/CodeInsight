#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  int64_t count = 0;
  while (true) {
    count++;
    int64_t num = count * count;
    if (num > N) {
      break;
    }
  }
  cout << (count - 1) * (count - 1) << endl;
}