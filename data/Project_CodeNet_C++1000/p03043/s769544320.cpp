#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin>>n>>k;
    double ans =0;
    cout.precision(15);

    for(int i=1;i<=n;i++)
    {
        if( i>=k)
        {
            ans += (n-i+1)/double(n);
            break;
        } else
        {
            int times = 0;
            int temp =i;
            while( temp<k)
            {
                temp=temp*2;
                times++;
            }
            ans += ( ( 1/double(n) )*( double(1)/ pow(2,times)) );
        }
    }
    cout<<ans;
}