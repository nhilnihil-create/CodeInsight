#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N,X;
int arr[300000];
ll sum[300000];
ll ans;
ll f(int K){
    ll ret = (ll)N*X+(ll)K*X;
    int cnt = 1;
    for(int i=N;i>0;i-=K){
        int e = i;
        int s = max(1,i-K+1);
        ret+=(sum[e]-sum[s-1])*(cnt==1?5:cnt*2+1);
        if(K!=1&&ret>ans) break;
        cnt++;
    }
    return ret;
}
int main(){
    scanf("%d %d",&N,&X);
    for(int i=1;i<=N;i++){
        scanf("%d",arr+i);
    }
    for(int i=1;i<=N;i++){
        sum[i]= sum[i-1] + arr[i];
    }
    ans = f(1);
    for(int i=1;i<=N;i++){
        ans = min(ans,f(i));
    }
    printf("%lld\n",ans);
    return 0;
}
