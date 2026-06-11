#include<bits/stdc++.h>

using namespace std;

int main() {
  int a, b=0, d=0;
  string s;
  cin >> a >> s;
  for(char c:s) {
    if (c=='B') b++;
    else d++;
  }
  cout << (d>b? "Yes" : "No") <<endl;
}