#include<bits/stdc++.h>
using namespace std;
int n,k,q,a[2005],ans=0x7fffffff,t[2005],b[2005],c[2005];
inline int min(int x,int y){
	return x<y?x:y;
}
void solve(int mn){
    int l=1,r=1,tot=0;
    while(l<=n){
        int cnt=0;
        while(l<=n&&a[l]<mn) l++;
        r=l;
        while(r<=n&&a[r]>=mn) r++;
        for(int i=l;i<=n&&i<r;i++)
            c[++cnt]=a[i];
        if(cnt>=k){
            sort(c+1,c+cnt+1);
            for(int i=1;i<=cnt-k+1;i++)
                b[++tot]=c[i];
        }
        l=r;
    }
    sort(b+1,b+tot+1);
    if(tot>=q) ans=min(ans,b[q]-b[1]);
}
int main(){
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[i]=a[i];
    }
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++) solve(t[i]);
    printf("%d\n",ans);
    return 0;
}