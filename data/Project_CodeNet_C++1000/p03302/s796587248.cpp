#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    while(cin>>a>>b)
    {
        if(a+b==15)
        {
            cout<<'+'<<endl;
            
        }
        else if(a*b==15)
        {
            cout<<'*'<<endl;
        }
        else
        {
            cout<<'x'<<endl;
            
        }
    }
    return 0;
}