#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k; 
  string s;
  cin >> s;
  int temp = s[k - 1] - 'A';
  s[k - 1] = temp + 'a';
  cout << s << '\n';
}