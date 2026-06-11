#include<bits/stdc++.h>
#define ll long long
#define mod 838627288460106
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll n,y,i,j,c10k=0,c5k=0,c1k=0;
    cin>>n>>y;
    bool ok=1;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            if(n-i-j>=0)
            {
                if(i*1000+j*5000+(n-i-j)*10000==y)
                {
                    cout<<n-i-j<<" "<<j<<" "<<i<<endl;
                    ok=0;
                    break;
                }
            }
        }
        if(!ok)
            break;
    }
    if(ok)
    {
        cout<<"-1 -1 -1"<<endl;
    }
    return 0;
}



