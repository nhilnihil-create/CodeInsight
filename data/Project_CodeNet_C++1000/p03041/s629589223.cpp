#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  k--;
  string s; cin >> s;
  int d = 'a' - 'A';
  s[k] += d;
  cout << s << endl;
}