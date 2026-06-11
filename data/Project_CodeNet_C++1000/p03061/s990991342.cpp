#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    ll N; cin>>N;
    ll a[N];
    rep(i,N){
        cin>>a[i];
    }
    ll s[N+1];
    ll t[N+1];
    //gcd 累積和作成
    s[0]=t[0]=0;
    rep1(i,N){
        s[i]=gcd(s[i-1],a[i-1]);
        t[i]=gcd(t[i-1],a[N-i]);
    }
    ll ans=0;
    rep(i,N){
        ans=max(ans,gcd(s[i],t[N-i-1]));
    }

    cout<<ans<<endl;


}