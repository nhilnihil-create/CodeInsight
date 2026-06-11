#include<iostream>
#include<cmath>

using namespace std;

int main(){
 int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  int n;
  n=max(x,y);
  
  int res=1000000000;
  for(int i=0;i<=n;i++){
   res=min(res,2*c*i+max(0,x-i)*a+max(0,y-i)*b);
  }
  
 cout << res << endl;
}