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
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    if(N % 2 == 0){
        ll cnt = 0;
        rep(i,N){
            REP(j,i+1,N){
                //rep(k,N){
                if(i==j) continue;
                if(i+j+2==N+1) continue;
                G[i].push_back(j);
                cnt++;
                //}
            }
        }
        cout << cnt << endl;
        rep(i,N){
            rep(j,G[i].size()){
                cout << i+1 << " " << G[i][j]+1 << endl;
            }
        }
    }else{
        ll cnt = 0;
        rep(i,N){
            REP(j,i+1,N){
                //rep(k,N){
                if(i==j) continue;
                if(i+j+2==N) continue;
                G[i].push_back(j);
                cnt++;
                //}
            }
        }
        cout << cnt << endl;
        rep(i,N){
            rep(j,G[i].size()){
                cout << i+1 << " " << G[i][j]+1 << endl;
            }
        }

    }
}
