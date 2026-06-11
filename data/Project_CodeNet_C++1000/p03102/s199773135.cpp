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

int main(){

  int N, M, C, a, b;
  cin >> N >> M >> C;
  int ans = 0;
  vector<int> arrB(M);
  vector<vector<int>> arrA(N, vector<int>(M));

  for (int i = 0; i < M; i++){
    cin >> b;
    arrB.at(i) = b;
  }

  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++) {
      cin >> a;
      arrA.at(i).at(j) = a;
    }
  }

  for (int i = 0; i < N; i++){
    int num = 0;
    for (int j = 0; j < M; j++) {
      num += arrB.at(j) * arrA.at(i).at(j);
    }
    num += C;
    if(num > 0) ans++;
  }

  cout << ans << endl;

  return 0;
}