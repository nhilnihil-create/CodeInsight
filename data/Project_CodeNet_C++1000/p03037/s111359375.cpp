#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

const long long mod = 1e9+7;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  int Gate_L = 0, Gate_R = 1e7;
  for(int i = 0; i < M; i++) {
    int L, R;
    cin >> L >> R;
    Gate_L = max(Gate_L, L);
    Gate_R = min(Gate_R, R);
  }

  if(Gate_L <= Gate_R) {
    cout << Gate_R - Gate_L + 1 << endl;
  }
  else {
    cout << 0 << endl;
  }

  return 0;
}
