#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x;
    cin>>a>>b>>x;
    if(x>a+b || x<a)
    {
        cout<<"NO"<<endl;
    }
    else
    {
       cout<<"YES"<<endl;
    }
    return 0;
}