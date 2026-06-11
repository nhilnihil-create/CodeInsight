#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int W;
  
  cin >> S >> W;
  
  float size = S.size();
 
  for(int i = 0; i < size/W; i++){
    cout << S.at(i*W);
  }
  cout << endl;
}
