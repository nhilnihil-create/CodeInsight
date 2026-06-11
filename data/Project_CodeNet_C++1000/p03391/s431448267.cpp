#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);

    long long a,b,n;
    while(~scanf("%lld",&n))
    {
        bool vis = true;
        long long minn = 0x3f3f3f3f;
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%lld%lld",&a,&b);
            if (a != b)
            {
                vis = false;
            }
            if (b < a)
                minn = min(minn,b);
                ans += b;
        }
        if (vis)
            puts("0");
        else
            printf("%lld\n",ans-minn);
    }



//    fclose(stdin);
    return 0;
}

