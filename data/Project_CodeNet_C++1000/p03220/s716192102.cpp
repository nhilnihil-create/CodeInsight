#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    ll N,T,A; cin>>N>>T>>A;
    vector<ll> H(N); rep(i,N)cin>>H.at(i);
    int res = 1;
    long double dif = fabs(T-H.at(0)*0.006-A);
    rep1(i,N){
        long double tmp = fabs(T-H.at(i)*0.006-A);
       // cout<<tmp<<endl;
        if(dif>tmp){
            res = i+1;
            dif = tmp;
        }
    }
    cout<<res<<endl;
}
