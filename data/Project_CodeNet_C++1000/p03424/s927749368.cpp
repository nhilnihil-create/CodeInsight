#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  string S;
  string Result="Three";
  cin >> N;
  
  rep(i, N){
    cin >> S;
    if (S == "Y"){
      Result = "Four";
      break;
    }
  }
  cout << Result << endl;
}
