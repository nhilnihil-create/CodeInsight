#include<bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n,k;
  cin >> n >> k >> s;
  string b="ABC";
  string l="abc";
  for (int i=0;i<3;i++){
    if (s.at(k-1)==b.at(i)) {
      s.at(k-1) = l.at(i);
    }
  }
  cout << s << endl;
}