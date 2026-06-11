#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  bool p = false;
  bool w = false;
  bool g = false;
  bool y = false;
  
  for(int i = 0; i < N; i++) { 
    char color;
    cin >> color;
    
    if (color == 'P') {
      p = true;
    } else if (color == 'W') {
      w = true;
    } else if (color == 'G') {
      g = true;
    } else if (color == 'Y') {
      y = true;
    }
  }
  if (p && w && g && y) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  } 
}