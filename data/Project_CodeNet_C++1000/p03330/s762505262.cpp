#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,C; cin>>N>>C;
    vector<vector<ll>> D(C+1,vector<ll>(C+1,0));
    rep(i,C)rep(j,C)cin>>D[i+1][j+1];
    vector<map<int,ll>> V(3);
    vector<vector<ll>> c(N,vector<ll>(N,0));
    rep(i,N)rep(j,N){
        cin>>c[i][j];
        V[(i+j)%3][c[i][j]]++;
    }
    ll res = -1;
    rep1(i,C){
        rep1(j,C){
            rep1(k,C){
                if(i==j||j==k||k==i)continue;
                ll tmp = 0;
                for(auto p:V[0]){
                    //turn i;
                    int color = p.first;
                    int cnt = p.second;
                    tmp += D[color][i]*cnt;
                }
                for(auto p:V[1]){
                    //turn j;
                    int color = p.first;
                    int cnt = p.second;
                    tmp += D[color][j]*cnt;
                }
                for(auto p:V[2]){
                    //turn k;
                    int color = p.first;
                    int cnt = p.second;
                    tmp += D[color][k]*cnt;
                }
                if(res==-1)res = tmp;
                else res = min(res,tmp);
            }
        }
    }
    cout<<res<<endl;
}
