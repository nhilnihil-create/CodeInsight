#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   double m;
   cin>>n;
   for(int i=n;i>=1;i--){
        m=pow(i,float(0.5));
        if(double(m-int(m))==0){
            cout<<i;
        break;
        }
   }
 return 0;
}
