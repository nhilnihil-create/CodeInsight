#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int a,b,c,d;
    cin>>a>>b;
    c = a+b;
    d = a*b;
    if(c==15)
    {
        cout<<"+"<<endl;
    }
    else if(d==15)
    {
        cout<<"*"<<endl;
    }
    else
    {
        cout<<"x"<<endl;
    }
    return 0;
}
