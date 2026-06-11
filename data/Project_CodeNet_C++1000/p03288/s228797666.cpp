#include<bits/stdc++.h>
using namespace std;
int main(void) {
  int r;
  cin >> r;
  if(r<1200) cout << "ABC" << endl;
  if((r>=1200) && (r<2800)) cout << "ARC" << endl;
  if(r>=2800) cout << "AGC" << endl;
}