#include<bits/stdc++.h>
#define ll              long long int
#define nl              '\n'
using namespace std;

int main(void){

   ll t,n,b,mx=0,sum=0;
   cin>>t;

   while(t--){
        cin>>n;

        mx=max(mx,n);

        sum +=n;
   }
   if(sum-mx<=mx) cout<<"No";
   else cout<<"Yes";
}
