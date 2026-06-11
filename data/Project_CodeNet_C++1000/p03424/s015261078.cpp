#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  string s;
  cin >> n;
  rep(i, n){
    cin >> s;
    if (s == "Y") {
      cout << "Four";
      return 0;
    }
  }
  cout << "Three";
}
