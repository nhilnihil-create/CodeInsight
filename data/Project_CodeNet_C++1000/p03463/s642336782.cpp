#include<bits/stdc++.h>

using namespace std;
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,t,x,y,z;
    
    cin>>n>>a>>b;
    
    x=max(a,b);
    
    y=min(a,b);
    
    z=x-y;
    

    if(z%2==0)
    {
        cout<<"Alice"<<endl;
    }
    else
        cout<<"Borys"<<endl;
        
}