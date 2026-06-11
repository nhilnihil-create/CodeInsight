#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N; cin >> N;
  int  i = 0;
  while (i < N) {
    i++;
    string arare;
    cin >> arare;
    if (arare == "Y") {
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;
}