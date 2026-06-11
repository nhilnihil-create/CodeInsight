#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);

  for (int i = 0; i < N;i++){
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int A = 0;
  int B = 0;
  for (int i = 0; i < N; i+=2) {
    A += v.at(i);
  }
  for (int i = 1; i < N;i+=2){
    B += v.at(i);
  }
  cout << A - B << endl;
}