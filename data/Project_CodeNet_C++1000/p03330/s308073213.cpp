#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define INF (1ll<<60)
#define mod 1000000007
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll N,C;cin>>N>>C;
    Graph D(C,vector<ll>(C)),c(N,vector<ll>(N));
    Graph cnt(3,vector<ll>(C));

    rep(i,C){
        rep(j,C){
            cin>>D[i][j];
        }
    }

    rep(i,N){
        rep(j,N){
            cin>>c[i][j];
            c[i][j]--;
            cnt[(i+j+2)%3][c[i][j]]++;
        }
    }

    ll ans=INF;
    rep(i,C){
        rep(j,C){
            if(i==j) continue;
            rep(k,C){
                if(k==i || k==j) continue;

                ll sum=0;
                rep(l,3){
                    rep(m,C){
                        if(l==0){
                            sum+=D[m][i]*cnt[l][m];
                        }else if(l==1){
                            sum+=D[m][j]*cnt[l][m];
                        }else if(l==2){
                            sum+=D[m][k]*cnt[l][m];
                        }
                    }
                }
                chmin(ans,sum);                
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}