// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S;
  long long K;
  cin >> S >> K;
  for (int i = 0; i < min((long long)S.size(), K); i++) {
    if (S[i] >= '2') {
      cout << S[i] << endl;
      return 0;
      }
  }
  cout << '1' << endl;

  return 0;
}
