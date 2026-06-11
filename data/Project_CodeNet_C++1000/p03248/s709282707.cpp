#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+5;
const int maxm=5e2+5;
const int maxq=55;
const int INF=0x3f3f3f3f;
char s[maxn];
int main()
{
    while(~scanf("%s",s+1))
    {
        int len=strlen(s+1);
        int ans=0;
        for(int i=1,j=len-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                ans=-1;
                break;
            }
        }
        if(s[len]=='1'||s[1]=='0'||s[len-1]=='0') ans=-1;
        if(ans==-1)
        {
            puts("-1");
            continue;
        }
        int root=1,now=1;
        for(int i=1;i<=len/2;i++)
        {
            if(s[i]=='1')
            {
                printf("%d %d\n",root,++now);
                root=now;
            }
            else
                printf("%d %d\n",root,++now);
        }
        for(int i=len/2+1;i<len;i++)
        {
            printf("%d %d\n",root,++now);
        }
    }
}
