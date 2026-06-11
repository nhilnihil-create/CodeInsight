#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c[100005];
int len,ans;
int main()
{
    scanf("%s",c+1);
    len=strlen(c+1);ans=len;
    for(int i=2;i<=len;i++)
        if(c[i]!=c[i-1])ans=min(ans,max(i-1,len-i+1));
    printf("%d",ans);
}


