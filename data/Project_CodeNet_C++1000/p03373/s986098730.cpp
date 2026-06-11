#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int tmp=0,tma,tmb;
  int a,b,c,x,y,lm;
  cin >> a >> b >> c >> x >> y;
  lm = max(x,y);
  long long int ta = x * a + y * b;
  for(int i=2;i<=lm*2;i=i+2){
    x--;
    y--;
    tmp = c * i;
    if(x>0)
      tma = (x)*a;
    else
      tma = 0;
    if(y>0)
      tmb = (y)*b;
    else
      tmb = 0;
    if(ta>tmp+tma+tmb)
      ta = tmp+tma+tmb;
  }
  cout << ta << endl;
}