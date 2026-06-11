#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, g, b;
  cin >> N >> A >> g >>b;
  if  (A + N > g + b) {
    cout << "Left" << endl;
  }else 
  if ( A + N < g + b ){
    cout << "Right" << endl;
  }else if(A + N == g + b ){
   cout << "Balanced"<< endl;
  }
}