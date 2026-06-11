#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<uint64_t> data(N + 1);
  data.at(0) = 2;
  data.at(1) = 1;
  for(int i = 2; i <= N; i++) {
    data[i] = data[i - 1] + data[i - 2];
  }
  printf("%ld\n", data.at(N) );
}