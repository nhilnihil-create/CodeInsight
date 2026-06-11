#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=305;
int n,a[maxn];
double exp[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
double solve(int cnt1,int cnt2,int cnt3)
{
    if(vis[cnt1][cnt2][cnt3])
        return exp[cnt1][cnt2][cnt3];
    vis[cnt1][cnt2][cnt3]=true;
    if(cnt1+cnt2+cnt3==0)
        return exp[cnt1][cnt2][cnt3]=0.0;
    double res=(double)n;
    if(cnt1) res+=solve(cnt1-1,cnt2,cnt3)*cnt1;
    if(cnt2) res+=solve(cnt1+1,cnt2-1,cnt3)*cnt2;
    if(cnt3) res+=solve(cnt1,cnt2+1,cnt3-1)*cnt3;
    res/=(double)(cnt1+cnt2+cnt3);
    return exp[cnt1][cnt2][cnt3]=res;
}
int main()
{
    scanf("%d",&n);
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1) cnt1++;
        if(a[i]==2) cnt2++;
        if(a[i]==3) cnt3++;
    }
    double ans=solve(cnt1,cnt2,cnt3);
    printf("%.12lf\n",ans);
    return 0;
}
