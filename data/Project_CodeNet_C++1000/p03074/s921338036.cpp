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

int main(){
    ll N,K;
    string S;
    cin >> N >> K >> S;
    vector<ll> v;
    ll now = 1;
    ll cnt = 0;
    rep(i,N){
        if(S[i]-'0' != now){
            v.push_back(cnt);
            cnt = 1;
            now = (now?0:1);
        }else{
            cnt++;
        }
    }
    if(!now){
        v.push_back(cnt);
        v.push_back(0);
    }else{
        v.push_back(cnt);
    }
    ll M = v.size();
    vector<ll> s(M+1);
    //PR(v,M);
    rep(i,M){
        s[i+1] = s[i] + v[i];
    }
    ll ans = 0;
    rep(i,M+1-K-K-1){
        cmax(ans, s[min(i+2*K+1,M)]-s[i]);
        i++;
    }
    if(M+1-K-K-1 <= 0){
        ans = s[M];
    }
    cout << ans << endl;
}