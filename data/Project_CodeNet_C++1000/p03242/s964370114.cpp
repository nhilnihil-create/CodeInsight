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
    int n;
    while(~scanf("%d",&n))
    {
        int num=0;int base=1;
        while(n)
        {
            int t=n%10;
            if(t==1) t=9;
            else if(t==9) t=1;
            num+=t*base;
            base*=10;
            n/=10;
        }
        printf("%d\n",num);
    }
}
