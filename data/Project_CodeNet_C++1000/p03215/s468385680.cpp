#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

//vector<vector<ll>> dp(1001,vector<ll>(1001));
vector<ll> S(1001),v;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
    }
    rep(i,N){
        S[i+1] = a[i] + S[i];
    }
    for(ll i=0;i<=N-1;i++){
        for(ll j=1;j<=N-i;j++){
            v.push_back(S[i+j]-S[i]);
        }
    }
    //cout << v.size() << endl;
    ll x=0;
    for(ll t=41;t>=0;t--){ 
        ll cnt = 0;
        //cout << x << endl;
        rep(i,((N*(N+1))/2)){
            if(((x+((1LL) << t)) & v[i]) == (x + ((1LL) << t))){
                cnt++;
            }
            if(cnt >= K)break;
        }
        if(cnt >= K){
            x += ((1LL) << t);
        }
    }
    cout << x << endl;
    /*

    priority_queue<ll> que;
    REP(i,0,N){
        rep(j,N-i){
            que.push(S[i+j+1] - S[i]);
            //dp[j][i] = S[j+i] - S[j];//beauty when used from j to i.
        }
    }
    ll ans = que.top();
    rep(i,K){
        ans = ans & que.top();
        //cout << que.top() << endl;
        que.pop();
    }
    cout << ans << endl;*/
}

