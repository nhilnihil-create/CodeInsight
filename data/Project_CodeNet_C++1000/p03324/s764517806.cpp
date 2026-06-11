#include<bits/stdc++.h>
using namespace std;
int main()
{   int d,n;
    cin>>d>>n;
    if(d==0)
    {
        if(n==100)
        {
            cout<<101<<"\n";
        }
        else{
        cout<<n<<"\n";}
    }
    if(d==1)
    {
       if(n==100)
       {
           cout<<101*100<<"\n";
       }
       else{
         cout<<n*100<<"\n";
       }
    }
    if(d==2)
    {
       if(n==100)
       {
           cout<<101*100*100<<"\n";
       }
       else{
         cout<<n*100*100<<"\n";
       }
    }
    return 0;
}