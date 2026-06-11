#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> vec(M);
  int count = 0;
  for(int i = 0; i < M; i++) {
    cin >> vec.at(i);
    if(vec.at(i) < X) {
      count++;
    }
  }
  if(count < M - count) {
    cout << count << endl;
  }
  else {
    cout << M - count << endl;
  }
}