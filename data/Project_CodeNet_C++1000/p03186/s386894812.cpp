#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a+b>=c)
    {
        cout<<b+c<<endl;
    }
    else{
        cout<<(a+b)*2+1-a<<endl;
    }
}
