#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> v(N),u;
    rep(i,N){
        v[i] = S[i] - '0';
    }
    ll now = 1;
    ll cnt = 0;
    rep(i,N){
        if(v[i] == now){
            cnt++;
        }else{
            u.push_back(cnt);
            i--;
            cnt = 0;
            now = (now?0:1);
        }
    }
    if(now == 1){
        u.push_back(cnt);
    }else{
        u.push_back(cnt);
        u.push_back(0);
    }
    ll M = u.size();
    //PR(u,M);
    vector<ll> us(M+1,0);
    rep(i,M){
        us[i+1] = us[i] + u[i]; 
    }
    if(M <= K*2){
        cout << us[M] << endl;
        return 0;
    }
    ll ans = 0;
    rep(i,M-K*2){
        cmax(ans,us[i+K*2+1] - us[i]);
        i++;
    }
    cout << ans << endl;
}