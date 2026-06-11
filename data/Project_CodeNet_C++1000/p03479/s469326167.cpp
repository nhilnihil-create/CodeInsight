#include<bits/stdc++.h>
using namespace std;

int main(){
   long long int X,Y;
   cin >> X >> Y;
long long int A = X;
long long int ans = 0;
   for(long long int i = X; i <= Y; i += A){
       ans++; 
       A = i;
   }

   cout << ans;
return 0;
}