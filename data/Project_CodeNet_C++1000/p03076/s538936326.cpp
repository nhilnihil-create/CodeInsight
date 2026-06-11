#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int ans=0;
    int m=0;

    for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;

        ans+=(a-a%10)+min(10,(a%10)*10);
        m=max(m,10-((a-1)%10+1));
    }

    ans-=m;

    cout<<ans<<"\n";

    return 0;
}
