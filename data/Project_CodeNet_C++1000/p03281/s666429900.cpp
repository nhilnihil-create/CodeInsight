#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    int ans=0;

    for(int i=1;i<=n;i+=2)
    {
        int num=i;
        for(int r=3;r<sqrt(n);r+=2)
        {
            if(num%r)continue;
            int cnt=0;
            for(;num%r==0;num/=r)cnt++;
            num*=(cnt+1);
        }
        if(num==8)ans++;
    }

    cout<<ans<<"\n";

    return 0;
}
