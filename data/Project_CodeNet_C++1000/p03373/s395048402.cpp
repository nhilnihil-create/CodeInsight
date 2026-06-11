#include <bits/stdc++.h>
using namespace std;


int main(){
   int a,b,c,x,y;
   long long sum = 0;
   cin >> a >> b >> c >> x >> y;
    
     if (c*2<a || c*2 <b){ 
         if (c*2>a && x>y){
             sum += (c*2*y)+(a*(x-y));
         }
        else if (c*2>b && y>x){
             sum += (c*2*x)+(a*(y-x));
         }
        else
        {
             sum += c*2*max(x,y);
        }
        
    }
    else if (a+b > c*2){
        if (x > y){
            sum += c * 2 * y;
            sum += a * (x - y);
        }
        else
        {
            sum += c * 2 * x;
            sum += b * (y - x);
        }
    }
    else{
        sum += (a * x) + (b * y);
    }    
    cout << sum << endl;
          
   
}

