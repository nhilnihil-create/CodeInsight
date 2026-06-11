#include <bits/stdc++.h>
using namespace std;
int main() {
  char c; cin >> c; map<char, char> df;
  df['A'] = 'T', df['T'] = 'A', df['G'] = 'C', df['C'] = 'G';
  cout << df.at(c) << endl;
}