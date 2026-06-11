#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
struct wjmzbmr
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
}a[maxn+5];
int mod[maxn+5];
int n;
vector<int> ans;
int main()
{

    scanf("%d",&n);
    for(int i=1;i<=n;++i) a[i].input(),mod[i]=abs(a[i].x+a[i].y)%2;
    int cnt[2]={0,0};
    for(int i=1;i<=n;++i) ++cnt[mod[i]];
    if(cnt[0]&&cnt[1]) return 0*printf("-1");
    bool flag=0;
    if(mod[1]==0)
    {
        ans.push_back(1);
        flag=1;
        for(int i=1;i<=n;++i) a[i].x--;
    }
    for(int i=0;i<31;++i) ans.push_back(1<<i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();++i)
    {
        printf("%d",ans[i]);
        if(i<int(ans.size())-1) printf(" ");else printf("\n");
    }
    for(int i=1;i<=n;++i)
    {
        int x=a[i].x,y=a[i].y;
        if(flag) printf("R");
        for(int j=0;j<30;++j)
        {
            if(x&1)
            {
                if((x+1+y)&2) printf("L"),x=(x+1)/2,y=y/2;
                else printf("R"),x=(x-1)/2,y=y/2;
            }
            else
            {
                if((x+y+1)&2) printf("D"),x/=2,y=(y+1)/2;
                else printf("U"),x/=2,y=(y-1)/2;
            }
        }
        if(x==-1) printf("L\n");
        if(x==1) printf("R\n");
        if(y==-1) printf("D\n");
        if(y==1) printf("U\n");
    }
    return 0;
}
