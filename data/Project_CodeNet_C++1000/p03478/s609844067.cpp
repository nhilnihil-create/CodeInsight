#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
           int n;
           cin >>n;
  int sum=0;
  int a,b;
  cin>>a>>b;

for(int i=1;i<=n;i++){
if(i<10){if(i>=a && i<=b)sum+=i;}
  else if(i<100 && i>=10){int c=i/10 %10,d=i%10;
                 if(c+d>=a && c+d <=b)sum+=i;}
  else if(i<1000 && i>=100){int c=i/10 %10,d=i%10,e=i/100%10;
                 if(c+d+e>=a && c+d+e <=b)sum+=i;}
   else if(i<10000&& i>=1000){int c=i/10 %10,d=i%10,e=i/100%10,f=i/1000%10;
                 if(c+d+e+f>=a && c+d+e+f<=b)sum+=i;}
  else{int c=i/10 %10,d=i%10,e=i/100%10,f=i/1000%10,g=i/10000%10;
                 if(c+d+e+f+g>=a && c+d+e+f+g <=b)sum+=i;}



}
  cout << sum <<endl;
}
