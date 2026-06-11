#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  cin >> x >> y;
  if((x+y)%2==0){
    cout << (x+y)/2 << endl;
  }
  if((x+y)%2==1){
    cout << (x+y)/2 +1 << endl;
  }
}