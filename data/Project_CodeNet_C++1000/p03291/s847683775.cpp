#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll n,a[100009],c[100009],_a[100009],_c[100009],q,jo3[100009];
ll ans;
string s;

// 3^k
ll jo(ll k){
    if(k==0)return 1;
    if(k<0)return 0;
    if(jo3[k])return jo3[k];
    return jo3[k]=(jo(k-1)*3)%mod;
}

int main(){
    cin>>s;
    n=s.size();
    rep(i,n){
        if(s[i]=='A')a[i+1]=1;
        if(s[i]=='C')c[i+1]=1;
        if(s[i]=='?')_a[i+1]=_c[i+1]=1,q++;
    }

    rep(i,n){
        a[i+1]+=a[i];
        _a[i+1]+=_a[i];
    }
    for(int i=n;i;i--){
        c[i]+=c[i+1];
        _c[i]+=_c[i+1];
    }

    for(int i=1;i<=n;i++){
        int x=q;
        if(s[i-1]=='?')x--;
        if(s[i-1]=='B'||s[i-1]=='?'){
            (ans+=a[i-1]*c[i+1]*jo(x))%=mod;
            (ans+=_a[i-1]*c[i+1]*jo(x-1))%=mod;
            (ans+=a[i-1]*_c[i+1]*jo(x-1))%=mod;
            (ans+=_a[i-1]*_c[i+1]*jo(x-2))%=mod;
        }
    }
    cout<<ans<<endl;
}