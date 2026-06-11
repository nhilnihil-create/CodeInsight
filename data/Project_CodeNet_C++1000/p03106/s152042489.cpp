#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;

int main()
{
   int k,a,b;
   scanf("%d%d%d",&a,&b,&k);
   for(int i=100;i>=1;i--){

   if(a%i==0 && b%i==0){
    k--;
   }
   if(k==0){
    cout<<i;
    return 0;
   }
   }
}
