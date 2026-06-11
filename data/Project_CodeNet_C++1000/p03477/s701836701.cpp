#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d, l, r;
  cin >> a >> b >> c >> d;
  l == a+b;
  r == c+d;
  if (a + b > c + d){
    cout << "Left" << endl;
  }else if (a + b < c + d){
    cout << "Right" << endl;
  }else{
    cout << "Balanced" << endl;
  }
}
