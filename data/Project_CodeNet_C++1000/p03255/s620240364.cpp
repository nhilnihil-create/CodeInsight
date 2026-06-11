#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int nn=200005;
int n,x,a[nn]; ll sum[nn],ans=-1;
int main(){
    int i,j,k;ll tmp;scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++){ scanf("%d",&a[i]); sum[i]=1ll*a[i]+sum[i-1]; }
    for(i=1;i<=n;i++){
        tmp=0;k=1;
        for(j=n;j>0&&tmp+1ll*i*x<ans;j-=i,k++){
            if(k==1) tmp+=5ll*(sum[j]-sum[max(0,j-i)]);
            else tmp+=(sum[j]-sum[max(0,j-i)])*(2ll*k+1ll);
        }
        if(ans==-1||tmp+1ll*i*x<ans) ans=tmp+1ll*i*x; 
    }
    cout<<ans+1ll*n*x<<endl;
    return 0;
}