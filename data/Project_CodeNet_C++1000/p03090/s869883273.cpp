#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N; cin>>N;
    vector<pair<int,int>> res;
    int B = N;
    if(N%2) B--;

    rep1(i,N){
        rep1(j,N){
            if(j<=i||j==B)continue;
            res.push_back({i,j});
        }
        B--;
    }
    cout<<res.size()<<endl;
    for(auto p: res)cout<<p.first<<" "<<p.second<<endl;
}
