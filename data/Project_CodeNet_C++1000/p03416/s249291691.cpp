#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B,a,b,c,d,e,aa,bb,cc,dd;
  cin >> A >> B;
 
  // ここにプログラムを追記
  int count = 0;
  for(int i=A; i<=B; i++){
    a=i/10000;
    aa = a*10000;
    b=(i-aa)/1000;
    bb=b*1000+aa;
    c=(i-bb)/100;
    cc=c*100+bb;
    d=(i-cc)/10;
    dd=d*10+cc;
    e=(i-dd);
    if(a==e && b==d)
      count++;
  }
  cout << count << endl;
}