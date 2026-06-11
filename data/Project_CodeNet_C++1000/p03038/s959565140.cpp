#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using graph = vector<vector<ll>>;
using vll = vector<ll>;


int main(){
    ll N,M;
    cin>>N>>M;
    vector<ll> A(N,0);
    vector<pair<ll,ll>> D(M);
    for(ll i=0;i<N;i++)cin>>A[i];
    sort(A.begin(),A.end());

    for(ll i=0;i<M;i++)
    {
        ll B,C;cin>>B>>C;
        D.emplace_back(make_pair(C,B));
    }
    sort(D.rbegin(),D.rend());

    ll res=0;
    ll K = 0;
    for(ll i=0;i<M;i++){
        for(ll j=0;j<D[i].second;j++)
        {
            if(N<=K)break;
            res+=max(D[i].first,A[K++]);//Cは大きい方から、Aは小さい方から
        }
    }
    for(ll i=K;i<N;i++)res+=A[i];
    cout<<res<<endl;
    return 0;
}

//大きい方からN個取り出すのがバゲットだとやりにくいとき、配列を作って取り出す手法を使う。