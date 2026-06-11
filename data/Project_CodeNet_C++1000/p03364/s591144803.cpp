#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
    }
    ll ans=0;
    rep(i,N){
        bool sym=true;
        rep(j,N){
            rep(k,N){
                if (S[j][k]!=S[k][j]){
                    sym=false;
                }
            }
        }
        if (sym){
            ans+=N-i;
        }
        rep(j,N){
            char s=S[j][0];
            rep(k,N){
                if (k!=N-1){
                    S[j][k]=S[j][k+1];
                }
                else {
                    S[j][k]=s;
                }
            }
        }
    }
    rep(i,N){
        bool sym=true;
        rep(j,N){
            rep(k,N){
                if (S[j][k]!=S[k][j]){
                    sym=false;
                }
            }
        }
        if (sym&&i!=0){
            ans+=N-i;
        }
        rep(j,N){
            char s=S[0][j];
            rep(k,N){
                if (k!=N-1){
                    S[k][j]=S[k+1][j];
                }
                else {
                    S[k][j]=s;
                }
            }
        }
    }
    cout << ans << endl;
}