#include <bits/stdc++.h>
using namespace std;

int main() {

  string N;
  int I_N = 0;
  cin >> N;

  int X = 0;
  for (int i = 0 ; i < (int)(N.length ()) ; i++) {
    char c = N[i];
    X += atoi (&c);
  }

  I_N = atoi (N.c_str ());

  if (I_N % X == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

