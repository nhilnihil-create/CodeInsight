#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力を受け取る
  string S;
  cin >> S;
  
  auto ret = count_if(S.begin(), S.end(), [](char a) { return a == '1'; });
  
  cout << ret << endl;
}