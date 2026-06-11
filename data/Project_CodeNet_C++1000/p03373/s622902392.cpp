#include <bits/stdc++.h>
using namespace std;

int main(){

int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
int64_t ans;
if(a+b<=c*2){
    ans=a*x+b*y;
}
else{
if(x>y){
    ans+=y*2*c;
    if(a<2*c){
      ans+=a*(x-y);
    }
    else{
      ans+=2*(x-y)*c;
    } 
}
if(y>=x){
     ans+=x*2*c;
     if(b<2*c){
      ans+=b*(y-x);
     }
    else{
      ans+=2*(y-x)*c;
    }     
}
}  
  
cout << ans << endl;
    return 0;  
  

}