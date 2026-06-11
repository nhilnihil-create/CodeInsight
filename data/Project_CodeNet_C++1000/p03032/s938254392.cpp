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

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> V(N);
    rep(i,N){
        cin >> V[i];
    }
    ll ans = 0;
    rep(T,K+1){
        rep(A,K-T+1){
            ll B = K-T-A;
            priority_queue<ll> que;
            ll sum = 0;
            rep(i,min(ll(A),N)){
                que.push(-V[i]);
            }
            rep(i,min(B,N)){
                if(N-1-i <= A-1)break;
                que.push(-V[N-1-i]);
            }
            rep(i,T){
                if(que.empty())break;
                if(que.top() < 0)break;
                que.pop();
            }
            while(!que.empty()){
                sum -= que.top();
                que.pop();
            }
            cmax(ans, sum);
        }
        //cout << T << endl;
    }
    cout << ans << endl;
}

