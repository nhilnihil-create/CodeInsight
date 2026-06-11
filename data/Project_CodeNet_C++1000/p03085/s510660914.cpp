#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<char, char> m;
  m['A'] = 'T';
  m['T'] = 'A';
  m['C'] = 'G';
  m['G'] = 'C';
  
  char b;
  cin >> b;
  cout << m[b] << '\n';

  return 0;
}