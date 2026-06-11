#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int sum = 0;
  int ans = 2147483647;
  int i = 0;
  while(i <= x || i <= y){
    sum = i*2*c + max(0,x-i)*a + max(0,y-i)*b;
    ans = min (ans,sum);
    i++;
  }
  cout << ans << endl;
  

}
