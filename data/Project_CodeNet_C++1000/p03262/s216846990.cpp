#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{

    int n,x;
    cin>>n>>x;
    int cor[n];
    for(int i=0;i<n;i++)
    {cin>>cor[i];cor[i]=abs(cor[i]-x);}
    if(n==1)
    {
        cout<<cor[0]<<endl;
        return 0;
    }

    int gcd=__gcd(cor[0],cor[1]);
    for(int i=2;i<n;i++)
    gcd=__gcd(gcd,cor[i]);
    cout<<gcd<<endl;
}