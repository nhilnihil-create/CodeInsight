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
    int N,K,Q;
    cin >> N >> K >> Q;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll ans=INF;
    rep(i,N){
        priority_queue<ll,vector<ll>,greater<ll>> pq; 
        int now=0;
        while(now<N){
            priority_queue<ll,vector<ll>,greater<ll>> pq2;
            while(now<N&&A[i]<=A[now]){
                pq2.push(A[now]);
                ++now;
            }
            ++now;
            while(pq2.size()>=K){
                pq.push(pq2.top());
                pq2.pop();
            }
        }
        if (pq.size()<Q) continue;
        rep(j,Q-1) pq.pop();
        ll maximum=pq.top();
        chmin(ans,maximum-A[i]);
    }
    cout << ans << endl;
}