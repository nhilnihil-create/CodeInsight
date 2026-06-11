#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N,K; cin>>N>>K;
    vector<ll> V(N); rep(i,N)cin>>V.at(i);
    ll res = 0;
    for(int l = 0; l <= min(N,K); l++){
        for(int r = 0; l+r <= min(N,K); r++){
            vector<ll> T;
            rep1(i,l)T.push_back(V.at(i-1));
            rep1(i,r)T.push_back(V.at(N-i));
            sort(T.begin(),T.end());
            int deq = K - l - r;
            int s = T.size();
            rep(i,min(deq,s)){
                if(T.at(i)<0)T.at(i)=0;
                else break;
            }
            ll now = 0;
            for(auto i: T){
                now += i;
            }
            res = max(res,now);
        }
    }
    cout<<res<<endl;
}
