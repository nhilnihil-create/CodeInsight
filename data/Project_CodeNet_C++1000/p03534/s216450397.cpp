/*
  ID: oodt
  PROG:
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=10005;
int n,m,k;
char ch[100050];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int a[27];

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    scanf("%s",ch);
    int n = strlen(ch);
    memset(a,0,sizeof(a));
    for(int i = 0; i < n; i++)
    {
        a[ch[i]-'a']++;
    }
    int ma = 0,mi = 0x3f3f3f3f;
    for(int i = 0; i < 27; i++)
    {
        if(a[i] != 0) {
            cnt++;
        ma = max(ma,a[i]);
        mi = min(mi,a[i]);
        }
    }
//    printf("%d %d %d",cnt,ma,mi);
    if(cnt > 2)
    {
        if(ma - mi > 1)
        {
            printf("NO\n");
        }
        else printf("YES\n");
    }
    else{
        if(cnt == 2 && n == 2) printf("YES\n");
        else if(n == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
