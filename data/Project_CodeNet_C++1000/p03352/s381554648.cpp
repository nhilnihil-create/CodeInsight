#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll X;
    cin>>X;
    ll ans=0;
    for(int i=1;i<=X;i++)
    {
        for(int j=2;j<=10;j++)
        {
            ll y=pow(i,j);
            if(y<=X)
                ans=max(ans,y);
        }
    }
    cout<<ans<<endl;
    return 0;
}
