#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  if (2*K-1<=N) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}