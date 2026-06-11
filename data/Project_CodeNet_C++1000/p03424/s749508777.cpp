#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  int j = 0;
  string s;
  
  cin >> N;
  
  rep(i, N){
 	cin >> s;
  	if (s == "Y") j++;
  }
  
  if (j > 0) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
}