#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N,M,Q; cin>>N>>M>>Q;
    vector<vector<int>> X(N+1,vector<int>(N+1,0));
    vector<vector<int>> C(N+1,vector<int>(N+1,0));
    rep(i,M){
        int l,r; cin>>l>>r;
        X.at(l).at(r)++;
    }
    rep1(i,N){
        C.at(i).at(1)=X.at(i).at(1);
        for(int j = 2; j <= N; j++){
            C.at(i).at(j)=C.at(i).at(j-1)+X.at(i).at(j);
        }
    } 
    rep(i,Q){
        int p,q; cin>>p>>q;
        int res = 0;
        for(int j = p; j <= q; j++){
            res += (C.at(j).at(q)-C.at(j).at(p-1));
        }
        cout<<res<<endl;
    }
    return 0;
}
