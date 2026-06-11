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
    ll H,W,D;
    cin>>H>>W>>D;
    ll A[H][W];
    pair<ll,ll> v[H*W+10];
    vector<ll>ans(H*W+10,0);
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cin>>A[i][j];
            v[A[i][j]].first=i;
            v[A[i][j]].second=j;
        }
    }
    for(ll i=1;i<=H*W;i++){
        if(ans[i]!=0) continue;
        for(ll j=i+D;j<=H*W;j+=D){
            ans[j]+=ans[j-D]+abs(v[j-D].first-v[j].first)+abs(v[j-D].second-v[j].second);
        }
    }

    ll Q;
    cin>>Q;
    ll L[Q],R[Q];
    for(ll i=0;i<Q;i++){
        cin>>L[i]>>R[i];
        cout<<ans[R[i]]-ans[L[i]]<<endl;
    }
}
