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
    int N,K; cin>>N>>K;
    vector<ll> x(N),y(N);
    vector<pair<ll,int>> X;
    rep(i,N){
        cin>>x[i]>>y[i];
        X.push_back({x[i],i});
    }
    ll res = 4e18;
    sort(X.begin(),X.end());
    for(int l = 0; l < N - K + 1; l++){
        for(int r = l + K - 1; r < N; r++){
            ll lx = X[r].first - X[l].first, ly = INF;
            vector<pair<ll,int>> Y;
            for(int k = l; k <= r; k++){
                int i = X[k].second;
                Y.push_back({y[i],i});
            }
            if(Y.size()<K)continue;
            sort(Y.begin(),Y.end());
            
            int ysize = Y.size();
            for(int s = 0; s <= ysize - K; s++){
                ly = min(ly,y[Y[s+K-1].second] - y[Y[s].second]);
            }
            res = min(res,lx*ly);
        }
    }
    cout<<res<<endl;
}
