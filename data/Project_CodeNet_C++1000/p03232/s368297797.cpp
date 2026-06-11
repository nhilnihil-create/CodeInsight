#include<bits/stdc++.h>
//dengyaotriangle
using namespace std;

const int maxn=100005;
const int mdn=1000000007;

inline long long qpow(long long bse,long long ex){
    long long ans=1;
    while(ex){if(ex&1)ans=(ans*bse)%mdn;ex>>=1;bse=(bse*bse)%mdn;}
    return ans;
}

int n;
int a[maxn];
long long fac[maxn],ifac[maxn];
long long pfx[maxn];

int main(){
    fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=(fac[i-1]*i)%mdn;
    ifac[maxn-1]=qpow(fac[maxn-1],mdn-2);for(int i=maxn-1;i>=1;i--)ifac[i-1]=(ifac[i]*i)%mdn;
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){pfx[i]=pfx[i-1]+a[i];pfx[i]%=mdn;}
    long long sum=pfx[n];
    for(int i=2;i<=n;i++){
        long long cinv=(fac[i-1]*ifac[i])%mdn;
        long long cnt=(pfx[n-i+1]+pfx[n]-pfx[i-1]+mdn*3ll)%mdn;
        //cerr<<i<<':'<<cnt<<endl;
        sum+=(cinv*cnt)%mdn;
        sum%=mdn;
    }
    cout<<(sum*fac[n])%mdn;
    return 0;
}