// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int cnt = K, g = 1;
  while (cnt < N) {
    g++;
    cnt += (K - 1);
  }
  cout << g << endl;

  return 0;
}
