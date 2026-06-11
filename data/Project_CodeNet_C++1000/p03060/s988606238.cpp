#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int ara[n],bra[n];
    int res=0;
    for(i=0;i<n;i++)
        cin>>ara[i];
    for(i=0;i<n;i++)
        cin>>bra[i];
    for(i=0;i<n;i++)
    {
        if(ara[i]>bra[i])
            res+=(ara[i]-bra[i]);
    }
    cout<<res<<endl;
    return 0;
}
