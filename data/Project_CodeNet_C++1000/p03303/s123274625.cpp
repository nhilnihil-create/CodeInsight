#include<bits/stdc++.h>
using namespace std;
int main()
{


   char ara[1000006];
   int n,i,j,len;

    cin>>ara>>n;
    len=strlen(ara);

     for(i=0;i<len;i+=n){

        cout<<ara[i];

     }


return 0;
}
