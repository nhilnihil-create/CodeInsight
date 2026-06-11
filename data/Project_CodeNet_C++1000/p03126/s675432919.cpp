#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,ll>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N,M;
    cin>>N>>M;
    vector<bool> like(M,true);
    rep(i,N){
        int K;
        cin>>K;
        vector<int> now(M,1);
        rep(j,K){
            int A;
            cin>>A;
            --A;
            now.at(A)=0;
        }
        rep(j,M){
            if(now.at(j))like.at(j)=false;
        }
    }
    int cnt=0;
    rep(i,M){
        if(like.at(i))cnt++;
    }
    cout<<cnt<<endl;
}