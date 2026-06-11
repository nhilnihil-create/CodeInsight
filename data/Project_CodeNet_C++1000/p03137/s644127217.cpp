#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
ll LCM(int a, int b){
    return a*b/gcd(a,b);
}

int main(void)
{
    int n,m;
    cin>>n>>m;
    vector<ll> x(m);
    rep(i,0,m)cin>>x[i];
    if(n>=m){ cout<<0<<endl; return 0;}
    sort(x.begin(),x.end());
    
    vector<ll> diff(m-1);
    rep(i,0,m-1){
        diff[i]=abs(x[i+1]-x[i]);
    }
    sort(diff.begin(), diff.end());

    ll ans=0;
    rep(i,0,m-n){
        ans+=diff[i];
    }
    cout<<ans<<endl;
    return 0;
}