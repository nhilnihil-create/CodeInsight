#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  ll a,b,c,x,y,z=0;
  cin >> a >> b >> c >> x >> y;
  c*=2;
  if(c>=a+b)cout << x*a+y*b<<endl;
  else if(c<=a&&c<=b)cout << c*max(x,y)<<endl;
  else if(a<=c&&b<=c&&a+b>=c){
    if(x>=y)cout << (x-y)*a+y*c<<endl;
    else cout << (y-x)*b+x*c<<endl;
  }
  else if(a<=c&&c<=b){
    cout << y*c+a*max(x-y,z)<<endl;
  }
  else if(b<=c&&c<=a){
    cout << x*c+b*max(y-x,z)<<endl;
  }
}