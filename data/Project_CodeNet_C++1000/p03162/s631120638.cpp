#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define nl printf("\n")
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
using namespace std;
int p[100002][4];
int a[100002][4];
int max_sum(int c,int i,int n){
    if(c>n) return 0;
    if(p[c][i]!=-1) return p[c][i];
    int j;
    int mx=0;
    for(j=0;j<3;j++){
        if(j==i) continue;
        mx=max(mx,a[c][j]+max_sum(c+1,j,n));
    }
    return p[c][i]=mx;
}
main()
{
    int n,ans;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        p[i][0]=-1;
        p[i][1]=-1;
        p[i][2]=-1;
        p[i][3]=-1;

    }
    ans=max_sum(1,3,n);
    printf("%d\n",ans);
}
