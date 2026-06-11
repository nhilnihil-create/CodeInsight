#include<iostream>
using namespace std;
int  main(){
    long long int  n,y;
    cin>>n>>y;
    bool found=false;
    for(long long int  i=0;i<=n;i++)
    {
        for(long long int  j=0;j<=n-i;j++)
        {
            long long int  rem=y-(10000*i)-(5000*j);
            long long int  r=n-i-j;
            if((rem%1000==0)&&(rem/1000==r)){
                cout<<i<<" "<<j<<" "<<r;
                found=true;
                break;
            }
        }
        if(found)
        break;
    }
    if(!found)
    {
        cout<<"-1 -1 -1\n";
    }
}