#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  if(x + y > a + b){
    cout << "Left" << endl;
  }else if(x + y == a + b){
    cout << "Balanced" << endl;
  }else cout << "Right" << endl;
}
