#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b;
  cin >> a >> b;
  if (a==b) cout << '=' << endl;
  else if (a=='A') cout << '<' << endl;
  else if (b=='A') cout << '>' << endl;
  else if (a=='B') cout << '<' << endl;
  else if (b=='B') cout << '>' << endl;
  else if (a=='C') cout << '<' << endl;
  else if (b=='C') cout << '>' << endl;
  else if (a=='D') cout << '<' << endl;
  else if (b=='D') cout << '>' << endl;
  else if (a=='E') cout << '<' << endl;
  else if (b=='E') cout << '>' << endl;
}