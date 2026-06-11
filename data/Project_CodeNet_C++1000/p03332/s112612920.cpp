#include<bits/stdc++.h>

using namespace std;

long long n,a,b,k,pref[300005],suff[300005],ans = 0;
const long long mod = 998244353;

long long BinPow(long long x,long long n){
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else{
        long long sum = BinPow(x,n/2);
        sum*=sum; sum%=mod;
        if(n%2!=0)
            sum*=x;
        sum%=mod;
        return sum;
    }
}

long long C(long long s,long long k){
    return (((pref[s]*suff[k])%mod)*suff[s-k])%mod;
}

int main(){
    cin.tie(0),ios::sync_with_stdio(0);
    cin>>n>>a>>b>>k;
    pref[0] = 1,suff[0] = 1;
    for(int i = 1;i<=n;i++){
        pref[i] = pref[i-1]*i;
        pref[i]%=mod;
    }
    for(int i = 1;i<=n;i++){
        suff[i] = BinPow(pref[i],mod-2);
        suff[i]%=mod;
    }
    for(long long i = 0;i<=n;i++){
        if((k-a*i)%b==0&&(k-a*i)>=0){
            long long times = (k-a*i)/b;
            if(times<=n){
                ans+=(C(n,times)*C(n,i))%mod;
                ans%=mod;
            }
        }
    }
    cout<<ans;
}
