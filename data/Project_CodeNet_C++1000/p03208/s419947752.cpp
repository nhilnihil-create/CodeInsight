// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  for(int i = 0; i < N; i++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  int min_hight = 1e9;
  for(int i = 0; i < N - K + 1; i++) {
    min_hight = min(min_hight, h[i + K - 1] - h[i]);
  }
  cout << min_hight << endl;
  return 0;
}
