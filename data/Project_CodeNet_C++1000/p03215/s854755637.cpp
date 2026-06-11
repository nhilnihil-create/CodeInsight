#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
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
    vector<ll> a(N), S(N+1), v,vv;
    rep(i,N){
        cin >> a[i];
    }
    rep(i,N){
        S[i+1] = a[i] + S[i];
    }
    //ll ans = 0;
    rep(l,N){
        REP(r,l+1,N+1){
            v.push_back(S[r] - S[l]);
        }
    }
    ll ans = 0;
    for(ll i = 40; i>=0; i--){
        ll cnt = 0;
        vv.clear();
        for(auto& b:v){
            if((1LL << i)&b){
                cnt++;
                vv.push_back(b);
            }
        }
        if(cnt >= K){
            ans += (1LL << i);
            v = vv;
        }
    }
    cout << ans << endl;
    /*
    vector<vector<ll>> S(N+1, vector<ll>(30));
    rep(i,N){
        rep(j,30){
            if((a[i]>>j)&1LL){
                S[i+1][j] = ((S[i][j]==0)?1LL:0LL);
            }else{
                S[i+1][j] = S[i][j];
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        REP(j,i+1,N+1){
            ll tmp = 0;
            rep(k,30){
                if(S[i][k] != S[j][k]){
                    tmp += (1LL << k);
                }
            }
            cmax(ans, tmp);
        }
    }
    cout << ans << endl;*/
}