using namespace std;
#include <bits/stdc++.h>

int main()
{
   int a,b,x;
   cin>>a>>b>>x;
   if(a<=x){
       if(a+b>=x){
           std::cout << "YES" << std::endl;
       }
       else{
           std::cout << "NO" << std::endl;
       }
   }
   else{
       std::cout << "NO" << std::endl;
   }
   return 0;
}
