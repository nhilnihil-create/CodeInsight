#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

struct SegMax{
    const ll INF=1e18;
    int n;
    vector<ll> dat;
    SegMax(int n_):n(),dat(n_*4,-INF){
        int x=1;
        while(n_>x){
            x*=2;
        }
        n=x;
    }

    void update(int i,ll x){//index iをxに更新する
        i+=n-1;
        dat[i]=x;
        while(i>0){
            i=(i-1)/2;
            dat[i]=max(dat[i*2+1],dat[i*2+2]);
        }
    }

    ll query(int a,int b){//a以上b未満の区間の最大値を求める
        return query_sub(a,b,0,0,n);
    }
    ll query_sub(int a,int b,int k,int l,int r){
        if(r<=a || b<=l){
            return -INF;
        }
        else if(a<=l && r<=b){
            return dat[k];
        }
        else{
            ll vl=query_sub(a,b,k*2+1,l,(l+r)/2);
            ll vr=query_sub(a,b,k*2+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }
};

int main() {
    int N;
    cin>>N;
    vector<int> h(N);
    rep(i,N){cin>>h.at(i);h.at(i)--;}
    vector<ll> a(N);
    rep(i,N)cin>>a.at(i);
    SegMax sm(N);
    rep(i,N){
        ll now=sm.query(0,h.at(i));
        chmax(now,0ll);
        now+=a.at(i);
        sm.update(h.at(i),now);
    }
    ll ans=sm.query(0,N);
    cout<<ans<<endl;
}