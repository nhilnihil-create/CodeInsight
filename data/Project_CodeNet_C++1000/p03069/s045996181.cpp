#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,ans,B=0,W=0;
    string S;
    cin>>N>>S;
    vector<ll> b(N,0),w(N,0);
    for(ll i=0;i<N;i++){
        if(S[i]=='#'){
            b[i]++;
            B++;
        }else{
            w[i]++;
            W++;
        }
        if(i!=N-1){
            b[i+1]=b[i];
            w[i+1]=w[i];
        }
    }
    ans=min(B,W);
    for(ll i=0;i<N;i++){
        ans=min(ans,b[i]+W-w[i]);
    }
    cout<<ans<<endl;
}