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
    deque<ll> V(N);
    rep(i,N){
        cin >> V[i];
    }
    ll ans = 0;
    rep(i,K+1){// i ko get
        rep(j,i+1){//j ko get from left
            deque<ll> U = V;
            deque<ll> T;
            ll tmp = 0;
            rep(k,j){
                if(U.empty()) break;
                tmp += U.front();
                if(U.front() < 0) T.push_back(U.front());
                U.pop_front();
            }
            rep(k,i-j){
                if(U.empty()) break;
                tmp += U.back();
                if(U.back() < 0) T.push_back(U.back());
                U.pop_back();
            }
            sort(T.begin(), T.end());
            rep(j,K-i){
                if(T.empty())break;
                tmp -= T.front();
                T.pop_front();
            }
            cmax(ans, tmp);
        }
    }
    cout << ans << endl;
}