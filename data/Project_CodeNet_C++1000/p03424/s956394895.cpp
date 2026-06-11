#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int p = 0,w = 0,g = 0,y = 0;

  for(int i = 0 ; i < N ; i++){
    string s;
    cin >> s;

    if (s == "P") p++;
    if (s == "W") w++;
    if (s == "G") g++;
    if (s == "Y") y++;
  }

  int c=0;
    if (p > 0) c++;
    if (w > 0) c++;
    if (g > 0) c++;
    if (y > 0) c++;

  if (c == 3) cout << "Three" << endl;
  if (c == 4) cout << "Four"  << endl;

}