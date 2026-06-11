#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int x = a^b;
    if(x%2==0)
    {
        cout<<"Alice"<<endl;
    }else{
        cout<<"Borys"<<endl;
    }
}