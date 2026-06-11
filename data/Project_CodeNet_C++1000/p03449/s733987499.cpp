#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  int N, a;
  cin >> N;
  int ans = 0;

  vector<vector<int>> vec(2, vector<int>(N));

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a;
      vec.at(i).at(j) = a;
    }
  }

  int x = N;
  for (int i = 0; i < N; i++) {
    int j = 0;
    int sum = 0;
    int k;
    for (k = 0; k < x; k++) {
      sum += vec.at(j).at(k);
    }
    j = 1;
    for (int l = k-1; l < N; l++) {
      sum += vec.at(j).at(l);
    }
    ans = max(ans, sum);
    x--;
  }

  cout << ans << endl;

  return 0;
}

