#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,count=0,pount=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    
    {
        for(int j=1;j<=n;j+=2)
        {   
            if(i%j==0)
            {
                count++;
            }
            
        }
        if(count==8)
        {
            pount++;
            count=0;
        }
        else{
        count=0;}
    }
    cout<<pount<<"\n";
    return 0;
}