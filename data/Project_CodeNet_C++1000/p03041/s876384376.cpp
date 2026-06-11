#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    if (i == k-1) {
      cout << (char)(s[i] + ('a'-'A'));
    } else {
      cout << s[i];
    }
  }
  cout << '\n';
}