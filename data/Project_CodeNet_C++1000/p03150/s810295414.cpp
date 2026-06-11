#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int N = S.size();
  string str = "keyence";
  int M = str.size();
  bool res = false;
  for (int i = 0; i <= M; i++){
    if (S.substr(0, i) == str.substr(0, i)){
      if (S.substr(N - M + i, M - i) == str.substr(i, M - i)){
        res = true;
      }
    }
  }
  cout << (res ? "YES" : "NO");
}