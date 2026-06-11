#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int x = x2-x1, y = y2-y1;
  cout << x2-y << " " << y2+x << " " << x1-y << " " << y1+x << endl;
  return 0;
}