#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
const int mod=1e9+7;
string s;
ll a[maxn],c[maxn],cnt1[maxn],cnt2[maxn];
ll mi[maxn];
void init()
{
    mi[0]=1;
    for(int i=1;i<maxn;i++){
        mi[i]=(mi[i-1]*3)%mod;
    }
}
int main()
{
    cin>>s;
    init();
    int len=s.length();
    for(int i=0;i<len;i++){
        a[i]=a[i-1]+(s[i]=='A'?1:0);
        cnt1[i]=cnt1[i-1]+(s[i]=='?'?1:0);
    }
    for(int i=len-1;i>=0;i--){
        c[i]=c[i+1]+(s[i]=='C'?1:0);
        cnt2[i]=cnt2[i+1]+(s[i]=='?'?1:0);
    }
    ll ans=0;
    for(int i=1;i<len-1;i++){
        if(s[i]=='B'||s[i]=='?'){
            int l=i-1,r=i+1;
            ans=(ans+a[l]*c[r]%mod*mi[cnt1[l]+cnt2[r]]%mod)%mod;
            ans=(ans+a[l]*cnt2[r]%mod*mi[cnt1[l]+cnt2[r]-1]%mod)%mod;
            ans=(ans+c[r]*cnt1[l]%mod*mi[cnt1[l]+cnt2[r]-1]%mod)%mod;
            ans=(ans+cnt1[l]*cnt2[r]%mod*mi[cnt1[l]+cnt2[r]-2]%mod)%mod;
        }
    }
    printf("%lld\n",ans);
}
