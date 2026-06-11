#include <bits/stdc++.h>
using namespace std;

int main(){
  int X1,Y1,X2,Y2;
  cin >> X1 >> Y1 >> X2 >> Y2;
  int dx=X2-X1;
  int dy=Y2-Y1;
  int X=X2;
  int Y=Y2;
  for(int i=0;i<2;i++){
    swap(dx,dy);
    dx=-dx;
    X+=dx;
    Y+=dy;
    cout << X << " " << Y;
    if(i==0){
      cout << " ";
    }
    else{
      cout << endl;
    }
  }
}