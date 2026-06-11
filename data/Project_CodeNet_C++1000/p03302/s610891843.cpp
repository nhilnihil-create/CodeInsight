#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int maxn=2e5;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a*b==15)
        {
            cout<<"*"<<endl;
        }
        else if(a+b==15)
        {
            cout<<"+"<<endl;
        }
        else
            cout<<"x"<<endl;
    }
    return 0;
}