#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,v,s=0,m=INT_MIN;
    cin>>n;
    while(n--)
    {
        cin>>v;
        m=max(m,v);
        s+=v;
    }
    cout<<s-m/2<<endl;

    return 0;
}
