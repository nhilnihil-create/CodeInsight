#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define re register
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define per(i,n,m) for(int i=m;i>=n;i--)
#define rrep(i,m,n) for(register int i=m;i<=n;i++)
#define rper(i,n,m) for(register int i=m;i>=n;i--)
const int N = 5e6 + 10;
const ll mod = 1e9 + 7;
bitset<N> bit;
signed main(){
    int n,ans=0;
    bit[0]=1;
    si(n);
    rep(i,1,n){
        int x;
        si(x);
        bit|=bit<<x;
        ans+=x;
    }
    rep(i,(ans+1)/2,N){
        if(bit[i]){
            pi(i);
            return 0;
        }
    }
   return 0;
}