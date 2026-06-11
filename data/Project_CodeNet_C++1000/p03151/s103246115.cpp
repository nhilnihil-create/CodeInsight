#include<cstdio>
#include<algorithm>
long long a[100005], b[100005];
long long have[100005];

long long min(long long a,long long b){ return a>b?b:a; }

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    for(int i = 1; i <= n; i++) scanf("%lld",&b[i]);
    long long need = 0; int size = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]<b[i]) need += b[i]-a[i], ans++;
        else if(a[i]>b[i]) have[++size] = a[i]-b[i];
    }
    std::sort(have+1,have+1+size);
    for(int i = size; i >= 1; i--){
        if(need==0) break;
        else{
            ans++;
            need -= min(have[i],need);
        }
    }
    if(need!=0) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
