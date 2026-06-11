#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e4+5;
const int maxm=5e2+5;
const int maxq=55;
const int INF=0x3f3f3f3f;
int main()
{
    int k;
    while(~scanf("%d",&k))
    {
        int even=k/2;
        int odd=k-even;
        int ans=even*odd;
        printf("%d\n",ans);
    }
}
