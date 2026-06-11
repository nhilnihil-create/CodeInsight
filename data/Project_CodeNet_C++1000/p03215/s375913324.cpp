#include<cstdio>
long long a[1005];
long long b[1000005];
int delet[1000005];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    int size = 0;
    for(int i = 1; i <= n; i++){
        long long sum = 0;
        for(int j = i; j <= n; j++){
            sum += a[j];
            b[++size] = sum;
        }
    }
    long long ans = 0;
    for(int i = 41; i >= 0; i--){
        long long base = 1ll<<i;
        int cnt = 0;
        for(int j = 1; j <= size; j++){
            if(!delet[j] && (b[j]&base)) cnt++;
        }
        if(cnt>=k){
            ans += base;
            for(int j = 1; j <= size; j++){
                if(!delet[j] && !(b[j]&base)) delet[j] = 1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
