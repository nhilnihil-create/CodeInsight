#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string A;
  A = "Three";
  cin >> N;
  for (int i = 0; i < N; i++){
  string S;
  cin >> S;
  if (S == "Y"){
    A = "Four";
    break;
  }
  }
  cout << A;
}