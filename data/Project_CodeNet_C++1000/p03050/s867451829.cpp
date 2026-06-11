#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

typedef long long ll;
using namespace std;
ll ans=0;
int main()
{
    ll N;
    ll i=1;
    scanf("%lld",&N);
    while(i*i<N)
    {
        if(N%i==0)
        {
            ll x=N/i-1;
            if(N%x!=0)
                ans+=x;
        }
        i++;
    }
    //ans=2499687339916;
    printf("%lld\n",ans);
    return 0;
}
