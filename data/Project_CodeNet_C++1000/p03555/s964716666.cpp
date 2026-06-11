#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string H,W;
  cin >> H >> W;
  
  if (H.at(0) == W.at(2) && H.at(1) == W.at(1) &&H.at(2) == W.at(0)){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
  
  