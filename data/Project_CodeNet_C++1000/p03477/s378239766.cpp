#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  int d;

  cin >> a >> b >> c >> d;
  int L = a+b;
  int R = c+d;

if(L>R){
    cout << "Left" << endl;

 }else  if(L<R){
        cout <<"Right" << endl;
 }else if(L==R){
     cout <<"Balanced"<< endl;

    }
}