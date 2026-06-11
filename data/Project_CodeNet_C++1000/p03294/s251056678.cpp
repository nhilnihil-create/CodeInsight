#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  
  vector<int>a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    sum += a.at(i)-1;
  }
  cout << sum << endl;
}
  