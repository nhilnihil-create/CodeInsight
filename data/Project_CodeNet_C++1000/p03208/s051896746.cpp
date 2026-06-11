#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,x,minn;
    cin>>n>>k;
    int ara[n];
    for(i=0;i<n;i++)
        cin>>ara[i];
    sort(ara,ara+n);
    minn=ara[n-1];
    for(i=0;i<=n-k;i++)
    {
        x=(ara[i+k-1]-ara[i]);
        minn=min(x,minn);
    }
    cout<<minn<<endl;
    return 0;
}
