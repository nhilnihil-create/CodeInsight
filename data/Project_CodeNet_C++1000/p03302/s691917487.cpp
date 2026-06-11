#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,sum,mul;
    cin>>a>>b;
    sum=a+b;
    mul=a*b;
    if(sum==15) cout<<"+"<<endl;
    else if(mul==15) cout<<"*"<<endl;
    else        cout<<"x"<<endl;
    return 0;
}
