#include <bits/stdc++.h>
using namespace std;

int main() {
  int s, c=1, finish=0;
  cin >> s;
  vector<int> V;
  
  while (true) {
    V.push_back(s);
    if (s%2==0) {
      s/=2;
    }
    else {
      s=3*s+1;
    }
    c++;
    for (int i=0; i<(int)V.size(); i++) {
      if (V[i]==s) {
        finish=1;
        break;
      }
    }
    if (finish==1) {break;}
  }
  cout << c << endl;
}

