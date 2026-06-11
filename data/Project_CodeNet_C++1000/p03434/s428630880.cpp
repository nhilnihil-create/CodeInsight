#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int A=0,B=0;
  for(int i = 0; i < N; i += 2) {
    A += vec.at(i);
    if(i + 1 >= N)
      break;
    B += vec.at(i + 1);
  }
  cout << A - B << endl;
}
