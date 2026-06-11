#include<bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  int cnt1=0,cnt2=0,cnt3=0;
  while(x>0||y>0){
    if(x>0&&y>0){
      if(a+b > 2*c){
	int t = min(x,y);
	x-=t; y-=t;
	cnt3 += 2*t;
      } else {
	int t = min(x,y);
	x-=t; y-=t;
	cnt1 += t; cnt2 += t;
      }
    } else {
      if(x > 0){
	if(a > 2*c){
	  cnt3 +=2*x;
	  x=0;
	} else {
	  cnt1 += x;
	  x = 0;
	}
      }

      
      if(y > 0){
	if(b > 2*c){
	  cnt3 +=2*y;
	  y=0;
	} else {
	  cnt2 += y;
	  y = 0;
	}
      }
    }
  }
  cout << cnt1 * a + cnt2 * b + cnt3 * c << endl;
  return 0;
}
