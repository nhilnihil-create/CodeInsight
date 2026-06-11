
#include<bits/stdc++.h>
using namespace std;
bitset<4000001> b;
string s;
int n,a[20001],sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    b=1;
    for(int i=1;i<=n;i++)
    {
        b=b|(b<<a[i]);
    }
    for(int i=(sum+1)>>1;1;++i)
    {
        if(b[i]){cout<<i<<endl;return 0;}
    }
    return 0;
}