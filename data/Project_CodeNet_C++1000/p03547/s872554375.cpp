#include <bits/stdc++.h>
using namespace std;

int main() {
  char S,T;
  cin >> S >> T;
  if (S > T)
    cout << '>' << endl;
  else if (S < T)
    cout << '<' << endl;
  else 
    cout << '=' << endl;
}
