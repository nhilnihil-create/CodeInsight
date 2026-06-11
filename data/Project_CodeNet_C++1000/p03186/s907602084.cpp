#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

template<class T> ll llpow(T x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}

#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define rep2(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)

long long INF = 1LL<<60;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    ll ans=0;
    ans+=2*min(b,c);
    int t=min(b,c);
    b-=t;
    c-=t;
    if(b>0)ans+=b;
    if(c>0){
        ans+=min(a,c);
        t=min(a,c);
        a-=t; c-=t;
        if(c>0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}


