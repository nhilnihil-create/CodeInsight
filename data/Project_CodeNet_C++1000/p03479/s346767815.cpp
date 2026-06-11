#include<bits/stdc++.h>
using namespace std;

int main(void){
   long long X,Y;
   cin>>X>>Y;
   int ans=0;
   while(1){
      ans++;
      X=X*2;
      if(X>Y) break;
   }
   cout<<ans<<endl;
   return 0;
}

