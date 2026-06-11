#include <bits/stdc++.h>
using namespace std;

int main(){
  int R, G , x;//(R + x)/2 = G
  cin >> R >> G;
  if(R >= 0 && G <= 4500){
    cout << 2 * G - R << endl;
  }
}