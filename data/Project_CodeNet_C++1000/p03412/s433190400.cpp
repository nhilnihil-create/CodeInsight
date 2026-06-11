#include <bits/stdc++.h>
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define Rrep(i,y,x) for(ll i=y;i>x;i--)
#define SIZE(a) ll(a.size())
#define vll vector<ll>
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define print(x) cout << (x) << endl
#define printvec(x) for(ll i=0;i<x.size();i++) cout << (x.at(i)) <<' ' 
typedef long long ll;
using namespace std;

int main(){
    ll N;
    cin>>N;
    vector<ll> A(N);
    rep(i,0,N){
        cin>> A.at(i);
    }
    vector<ll> B(N);
    rep(i,0,N){
        cin>> B.at(i);
    }
    vector<ll> num(30);
    vector<ll> L(N),K(N);
    rep(i,0,30){
        ll t = (ll)pow(2,i);
        rep(i,0,N){
            K.at(i)=A.at(i)%(2*t);
            L.at(i)=B.at(i)%(2*t);
        }
        sort(L.begin(),L.end());
        ll a=0;
        rep(i,0,N){
            ll k=K.at(i);
            ll x= lower_bound(L.begin(),L.end(),2*t-k)-lower_bound(L.begin(),L.end(),t-k);
            ll y= lower_bound(L.begin(),L.end(),4*t-k)-lower_bound(L.begin(),L.end(),3*t-k);
            a = (a+x+y)%2;
        }
        num.at(i)=a;
    }
    ll ans=0,s=1;
    rep(i,0,30){
        ans+=num.at(i)*s;
        s*=2;
    }
    print(ans);


}


