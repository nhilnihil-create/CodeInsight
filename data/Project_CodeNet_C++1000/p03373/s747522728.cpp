#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int rmax = max(2*X, 2*Y);
  int Anum = 0, Bnum = 0;
  int min = A*X + B*Y;

  int r = rmax;
  while(r >= 0){
    //r枚のABを買うとき
    Anum = r/2;
    Bnum = r/2;
    int money = r * C;
    if(X - Anum > 0) money += (X - Anum) * A;
    if(Y - Bnum > 0) money += (Y - Bnum) * B;
    if(min > money) min = money;
    r--;
  }
  cout << min << endl;
}