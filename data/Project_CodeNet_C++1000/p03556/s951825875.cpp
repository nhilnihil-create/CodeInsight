#include<bits/stdc++.h>
using namespace std;
int main()
{
   long int n,x;
   cin>>n;
   while(1){
    x=sqrt(n);

    if(x*x == n){
        cout<<n;
        break;
    }
    else n--;
   }
}