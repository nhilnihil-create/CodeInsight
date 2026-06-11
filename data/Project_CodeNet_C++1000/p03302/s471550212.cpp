#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
  cin >> x >> y;
  if(x + y == 15)
    cout << '+' << endl;
  else if (x * y == 15)
    cout << '*' << endl;
  else
    cout << 'x' << endl;
}