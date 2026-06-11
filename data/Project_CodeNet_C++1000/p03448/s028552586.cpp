#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,x,ans=0;
    cin>>a>>b>>c>>x;
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            for(int k=0;k<=c;k++)
                if((i*500+j*100+k*50)==x)
                    ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}