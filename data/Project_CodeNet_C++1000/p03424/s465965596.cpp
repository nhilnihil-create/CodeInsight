#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
    cin >> N;
  rep(i,N) {
    string S_i;
    cin >> S_i;
    
    if(S_i == "Y") {
      cout << "Four" << endl;
      break;
    }
    
    if(i == N-1 && S_i != "Y") {
      cout << "Three" << endl;
    }
  }
}