#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> V(4);
  int yymm=1, mmyy=1;
  for (int i=0; i<4; i++) {
    cin >> V[i];
  }
  if ((V[0]-'0')*10+(V[1]-'0')>12 || (V[0]-'0')*10+(V[1]-'0')<1) {
    mmyy=0;
  }
  if ((V[2]-'0')*10+(V[3]-'0')>12 || (V[2]-'0')*10+(V[3]-'0')<1) {
    yymm=0;
  }
  
  if (mmyy==1 && yymm==1) {
    cout << "AMBIGUOUS" << endl;
  }
  else if (mmyy==0 && yymm==1) {
    cout << "YYMM" << endl;
  }
  else if (mmyy==1 && yymm==0) {
    cout << "MMYY" << endl;
  }
  else if (mmyy==0 && yymm==0) {
    cout << "NA" << endl;
  }
}
