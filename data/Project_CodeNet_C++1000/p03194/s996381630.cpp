#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int maxn = 1e5+7,mod = 1e9+7;
ll read(){
    ll c = getchar(),Nig = 1,x = 0;
    while(!isdigit(c))
        c = getchar();
    if(c == '-')
        Nig = -1,c = getchar();
    while(isdigit(c))
        x = ((x<<1) + (x<<3)) + (c^'0'),c = getchar();
    return Nig*x;
}
#define read read()
ll Pow(ll a,int b,ll ans = 1){
    for(;b;b>>=1,a *= a)
        if(b&1)
            ans *= a;
    return ans;
}
int main(){
    ios;
    ll n = read,p = read,ans = 1;
    for(ll i=2;i*i<=p;i++){
        if(p%i)continue;
        int cnt = 0;
        while(p%i==0)
            cnt++,p/=i;
        ans *= Pow(i,cnt/n);
    }
    if(p!=1){
        if(n == 1)
            ans *= p;
    }
    cout<<ans<<endl;
    return 0;
}
