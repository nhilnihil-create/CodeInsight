#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
int main() {
  vector<char> s(3); 
  for (int i; i<3; i++) cin >> s.at(i);
  sort ( s.begin(), s.end() );
  if(s.at(0)=='a'&&s.at(1)=='b'&&s.at(2)=='c') cout << "Yes" << endl;
  else cout << "No" << endl;
}

