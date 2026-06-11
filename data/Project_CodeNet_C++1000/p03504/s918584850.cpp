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
    ll N,C;
    cin >> N >> C;
    vector<ll> s(N), t(N), c(N);
    vector<vector<ll>> S(C, vector<ll>(100010));
    rep(i,N){
        cin >> s[i] >> t[i] >> c[i];
        s[i]--;t[i]--;c[i]--;
        S[c[i]][s[i]]++;
        S[c[i]][t[i]]--;
    }
    vector<ll> SS(100010);
    rep(i,100010){
        rep(j,C){
            if(S[j][i] > 0){
                if(i == 0){
                    continue;
                }else{
                    S[j][i-1]++;
                    S[j][i]--;
                }
            }
            //SS[i] += S[c[j]][i];
        }
    }
    rep(i,100010){
        rep(j,C){
            SS[i] += S[j][i];
        }
    }
    ll ans = 0;
    rep(i,100009){
        SS[i+1] += SS[i]; 
    }
    rep(i,100010){
        cmax(ans, SS[i]);
    }
    cout << ans << endl;
}
