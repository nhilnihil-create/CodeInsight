#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,AB,X,Y;
  cin >> A >> B >> AB >> X >> Y;
  int price=1000000001;
  for(int i=0;i<X+1;i++){
    int ab = (X-i)*2;
    int y = max(Y-ab/2,0);
    int x = i*A+y*B+ab*AB;
    price=min(price,x);
  }
  for(int i=0;i<Y+1;i++){
    int ab = (Y-i)*2;
    int y = max(X-ab/2,0);
    int x = i*B+y*A+ab*AB;
    price=min(price,x);
  }
  cout << price << endl;
}
