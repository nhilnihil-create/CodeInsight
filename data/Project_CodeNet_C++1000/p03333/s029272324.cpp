#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<ll> L(N),R(N);
    rep(i,N) cin >> L[i] >> R[i];
    multiset<Pll> sl,sr;
    rep(i,N){
        sl.insert(Pll(L[i],i));
        sr.insert(Pll(R[i],i));
    }
    ll sum=0,now=0;
    bool right=true;
    while(!sl.empty()){
        if (right){
            Pll p=*sl.rbegin();
            ll next=p.first-now;
            if (next>0){
                sum+=next;
                now=p.first;
                sr.erase(sr.lower_bound(Pll(R[p.second],p.second)));
                sl.erase(sl.lower_bound(p));
                right=false;
            }
            else break;
        }
        else {
            Pll p=*sr.begin();
            ll next=now-p.first;
            if (next>0){
                sum+=next;
                now=p.first;
                sl.erase(sl.lower_bound(Pll(L[p.second],p.second)));
                sr.erase(sr.begin());
                right=true;
            }
            else break;
        }
    }
    sum+=abs(now);
    ll ans=sum;
    sl.clear(),sr.clear();
    rep(i,N){
        sl.insert(Pll(L[i],i));
        sr.insert(Pll(R[i],i));
    }
    sum=0,now=0;
    right=false;
    while(!sl.empty()){
        if (right){
            Pll p=*sl.rbegin();
            ll next=p.first-now;
            if (next>0){
                sum+=next;
                now=p.first;
                sr.erase(sr.lower_bound(Pll(R[p.second],p.second)));
                sl.erase(sl.lower_bound(p));
                right=false;
            }
            else break;
        }
        else {
            Pll p=*sr.begin();
            ll next=now-p.first;
            if (next>0){
                sum+=next;
                now=p.first;
                sl.erase(sl.lower_bound(Pll(L[p.second],p.second)));
                sr.erase(sr.begin());
                right=true;
            }
            else break;
        }
    }
    sum+=abs(now);
    chmax(ans,sum);
    cout << ans << endl;
}