#include<cstdio>
#include<algorithm>
long long a[200005];
long long sum[200005], sumr[200005];
//for the middle

long long min(long long a,long long b){ return a>b?b:a; }

long long getValue(long long x,long long y,long long u,long long v){
    long long b[5];
    b[0] = x, b[1] = y, b[2] = u, b[3] = v;
    std::sort(b,b+4);
    return b[3]-b[0];
}

void upDate(int x,int y,int z,int n,long long &ans){
    if(x>=1 && y>x && z>y && z<n){
        long long cur = getValue(sum[x],sum[y]-sum[x],sum[z]-sum[y],sum[n]-sum[z]);
        ans = min(ans,cur);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    sum[0] = 0;
    for(int i = 1; i <= n; i++){ 
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    int p0 = 0, p1 = 0;
    long long ans = 1e18+7;
    for(int i = 1; i <= n; i++){
        long long partL = sum[i], partR = sum[n]-sum[i];
        while(p0+1<i && 2*sum[p0+1]<=partL) p0++;
        while(p1<i+1 || (p1+1<n && 2*(sum[p1+1]-sum[i])<=partR)) p1++;
        //printf("p0 = %d, i = %d, p1 = %d\n",p0,i,p1);
        upDate(p0,i,p1,n,ans);
        upDate(p0,i,p1+1,n,ans);
        upDate(p0+1,i,p1,n,ans);
        upDate(p0+1,i,p1+1,n,ans);
    }
    printf("%lld\n",ans);
    return 0;
}
