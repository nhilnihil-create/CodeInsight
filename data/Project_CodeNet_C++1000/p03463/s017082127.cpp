#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b;
  cin >> N >> a >> b;
  int diff = b - a;
  if(diff == 1){
    cout << "Borys" << endl;
  }else if(diff % 2 == 0){
    cout << "Alice" << endl;
  }else if(diff % 2 == 1){
    cout << "Borys" << endl;
  }else{
    cout << "Draw" << endl;
  }
}
