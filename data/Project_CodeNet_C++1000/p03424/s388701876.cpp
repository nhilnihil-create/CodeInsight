#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S, n = "Three";
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> S;
    if (S == "Y"){
      n = "Four";
    }
  }
  cout << n <<endl;
}