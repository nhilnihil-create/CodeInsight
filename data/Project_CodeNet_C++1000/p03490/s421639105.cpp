#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a,n,sizeof(a))
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
const int mod=1e9+7;
const double eps=1e-6;
const int N=1e4+5;
const int w=20003;
char s[N];
bool flag[2][2][40009];
int main()
{
    int _x=0,x,y,p,q,sum,now=1;
    scanf("%s%d%d",s+1,&x,&y);
    int len=strlen(s+1);
    x+=w,y+=w;
    while(now<=len&&s[now]=='F') now++,_x++;
    flag[0][0][w+_x]=flag[1][0][w]=1;
    while(now<=len)
    {
        now++;
        sum=0;
        p^=1;
        q^=p;
        while(now<=len&&s[now]=='F') sum++,now++;
        for(int i=w-len;i<=w+len;i++)
            flag[p][q][i]=flag[p][q^1][i+sum]|flag[p][q^1][i-sum];
    }
    if(p==1&&flag[0][q^1][x]&&flag[1][q][y]||p==0&&flag[0][q][x]&&flag[1][q][y])
        puts("Yes");
    else puts("No");
    return 0;
}
