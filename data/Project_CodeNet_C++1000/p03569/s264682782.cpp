#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 410000;

int n,m;
char str[maxn];
char s[maxn];
int pos[maxn];

int main()
{
    scanf("%s",str); n=strlen(str);
    m=0; for(int i=0;i<n;i++) if(str[i]!='x') pos[m]=i,s[m++]=str[i];
    if(!m) return puts("0"),0;

    for(int i=0;i<m;i++) if(s[i]!=s[m-i-1]) return puts("-1"),0;
    int ans=0;
    int lai=0,laj=n-1,j=m-1;
    for(int i=0;i<=j;i++,j--)
    {
        int x=pos[i]-lai,y=laj-pos[j];
        if(x!=y) ans+=abs(x-y);
        lai=pos[i],laj=pos[j];
    }
    printf("%d\n",ans);

    return 0;
}