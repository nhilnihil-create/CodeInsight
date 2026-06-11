#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  char b;
  cin >> b;
  switch (b) {
    case 'A':
      b = 'T';
      break;
    case 'T':
      b = 'A';
      break;
    case 'C':
      b = 'G';
      break;
    case 'G':
      b = 'C';
      break;
  }

  cout << b << endl;
}