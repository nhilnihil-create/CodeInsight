#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
ll N;
int main()
{
    scanf("%lld",&N);
        ll n=sqrt(N);
        ll m;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(N%i==0)
            {
                m=N/i-1;
                if(m==0)
                {
                    continue;
                }
                if(N/m==N%m)
                {
                    ans+=m;
                }
            }
        }
        cout<<ans<<endl;
    return 0;
}
