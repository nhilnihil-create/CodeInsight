#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  int price=700;
  rep(i,3){
    if(s[i]=='o'){
      price += 100;
    }
  }
  cout << price << endl;
}