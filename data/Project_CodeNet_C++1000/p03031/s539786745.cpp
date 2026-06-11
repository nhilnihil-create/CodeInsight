#include<bits/stdc++.h>

using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)
#define sc2(a,b)  scanf("%d %d",&a,&b)

int main(){
    int n,m,ans=0;
    sc2(n,m);
    int k[15][15];
    int p[15]={0};
    rep(i,15) rep(j,15) k[i][j]=0;
    rep(i,m) {
        sc1(k[i][0]);
        rep(j,k[i][0]) sc1(k[i][j+1]);
    }
    rep(i,m) sc1(p[i]);
    rep(i,pow(2,n)) {
        int x=i;
        int s[15]={0};
        rep(j,n) {
            if (x&1)  s[j]=1;
            x=x>>1;
        }
        int chk=0;
        rep(j,m) {
            int cnt=0;
            rep(a,k[j][0]) if (s[k[j][a+1]-1]==1) cnt=(cnt+1)%2;
            if (cnt==p[j]) chk++;
        }
        if (chk==m) ans++;
    }
    printf("%d\n",ans);

    return 0;
}
