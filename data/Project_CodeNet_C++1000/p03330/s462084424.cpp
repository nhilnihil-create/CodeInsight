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
    vector<vector<ll>> D(C,vector<ll>(C)), c(N,vector<ll>(N));
    rep(i,C){
        rep(j,C){
            cin >> D[i][j];
        }
    }
    map<ll,ll>mp[3];
    rep(i,N){
        rep(j,N){
            cin >> c[i][j];
            c[i][j]--;
            mp[(i+j+2)%3][c[i][j]]++;
        }
    }
    ll ans = 1e18;
    rep(s,C){
        REP(t,0,C){
            REP(r,0,C){
                if(s==t || t==r || r==s)continue;
                ll tmp = 0;
                rep(i,C){
                    tmp += D[i][s]*mp[0][i];
                    tmp += D[i][t]*mp[1][i];
                    tmp += D[i][r]*mp[2][i];
                }
                /*
                rep(i,N){
                    rep(j,N){
                        if((i+j+2)%3 == 0){
                            if(c[i][j] != s){
                                tmp += D[c[i][j]][s];
                            }
                        }else if((i+j+2)%3 == 1){
                            if(c[i][j] != t){
                                tmp += D[c[i][j]][t];
                            }
                        }else{
                            if(c[i][j] != r){
                                tmp += D[c[i][j]][r];
                            }
                        }
                    }
                }
                */
                cmin(ans,tmp);
            }            
        }
    }
    cout << ans << endl;
}

