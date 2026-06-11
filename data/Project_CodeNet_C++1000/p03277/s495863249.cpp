#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

struct BIT{
private:
    vector<ll> a;
    int n;
public:
    BIT(int sz){
        n=sz;
        a.resize(sz+1);
    }
    ll sum(int i){
        ll res=0;
        while(i>0){
            res+=a[i];
            i-=i&-i;
        }
        return res;
    }
    ll sum(int i,int j){
        return sum(j)-sum(i-1);
    }
    void add(int i,ll x){
        while(i<=n){
            a[i]+=x;
            i+=i&-i;
        }
    }
};

int main(){
    ll n;
    cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll s[n+1];
    s[0]=0;
    ll lb=0,ub=inf;
    while(ub-lb>1){
        ll x=(ub+lb)/2;
        rep(i,n){
            if(a[i]<=x)s[i+1]=1;
            else s[i+1]=0;
            s[i+1]+=s[i];
        }
        rep(i,n+1){
            s[i]=2*s[i]-i;
        }
        pair<int,int> p[n+1];
        rep(i,n+1){
            p[i]=make_pair(s[i],-i);
        }
        sort(p,p+n+1);
        BIT bit(n+1);
        ll cnt=0;
        rep(i,n+1){
            int it=-p[i].second;
            cnt+=bit.sum(it);
            bit.add(it+1,1);
        }
        if(cnt<n*(n+1)/4+1)lb=x;
        else ub=x;
    }
    cout<<ub<<endl;
}
