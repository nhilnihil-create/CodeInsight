#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int a,b,c,d,e,f,g = 0;
  int aa,bb,cc,dd,ee;
  int ans = 0;
  cin >> a >> b >> c >> d >> e;
  aa = a % 10; 
  if(aa == 0){
    ans += a;
    a = 0;
  }
  bb = b % 10; 
  if(bb == 0){
    ans += b;
    b = 0;
  }
  cc = c % 10; 
  if(cc == 0){
    ans += c;
    c = 0;
  }
  dd = d % 10; 
  if(dd == 0){
    ans += d;
    d = 0;
  }
  ee = e % 10; 
  if(ee == 0){
    ans += e;
    e = 0;
  }
  
  f = min({(aa+9)%10,(bb+9)%10,(cc+9)%10,(dd+9)%10,(ee+9)%10});
  f++;
 
  if(aa == f){
    ans += (a+b+c+d+e);
    ans += ((10-bb)%10+(10-cc)%10+(10-dd)%10+(10-ee)%10);
  }
  else if(bb == f){
    ans += (a+b+c+d+e);
    ans += ((10-aa)%10+(10-cc)%10+(10-dd)%10+(10-ee)%10);
  }
  else if(cc == f){
    ans += (a+b+c+d+e);
    ans += ((10-aa)%10+(10-bb)%10+(10-dd)%10+(10-ee)%10);
  }
  else if(dd == f){
    ans += (a+b+c+d+e);
    ans += ((10-aa)%10+(10-bb)%10+(10-cc)%10+(10-ee)%10);
  }
  else if(ee == f){
    ans += (a+b+c+d+e);
    ans += ((10-aa)%10+(10-bb)%10+(10-cc)%10+(10-dd)%10);
  }  
  cout << ans << endl;
}
