#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,r,s,i,x,y;
    cin>>n>>q;
    int ara[n];
    memset(ara,0,sizeof ara);
    string str;
    cin>>str;
    for(i=0;i<n-1;i++)
    {
        if(str[i]=='A' && str[i+1]=='C')
            ara[i+1]=1,i++;
    }
    for(i=1;i<n;i++)
        ara[i]+=ara[i-1];

    while(q--)
    {
        cin>>x>>y;
        x--;
        y--;
        r=ara[y];
        s=ara[x];

        cout<<(r-s)<<endl;
    }
    return 0;
}
