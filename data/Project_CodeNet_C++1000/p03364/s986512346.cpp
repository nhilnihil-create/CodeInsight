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
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
    }
    ll cnt = 0;
    rep(i,N){
        rep(j,N){
            rep(k,N){
                if(S[j][k] != S[k][j]){
                    goto gt;
                }
            }
        }
        cnt++;
        gt:
        rep(j,N){
            rotate(S[j].begin(), S[j].begin()+1, S[j].end());
        }
    }
    cout << cnt*N << endl;
}