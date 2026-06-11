#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ll n; cin>>n;
   ll count=0,num;
   for(int i=0;i<n;i++){
       cin>>num;
       while(num%2==0){
           num/=2;
           count++;
       }
   }
   cout<<count;
   return 0;
}
