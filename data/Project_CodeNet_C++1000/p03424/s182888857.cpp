#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int Y = 0;
  int N;
  string S;
  
  cin >> N;
  
  rep(i, N) {
    cin >> S;
    if(S == "Y") {
    	Y++;
    }
  }

  if(Y == 0) {
    cout << "Three" << endl;
  }
  else {
   	cout << "Four" << endl; 
  }
}
