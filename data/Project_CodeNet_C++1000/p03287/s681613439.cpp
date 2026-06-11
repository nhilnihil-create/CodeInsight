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
    ll N,M,ans=0;
    cin>>N>>M;
    ll A[N+1];
    A[0]=0;
    for(ll i=1;i<=N;i++){
        cin>>A[i];
        A[i]+=A[i-1];
    }
    map<ll,ll> m;
    for(ll i=0;i<=N;i++){
        A[i]%=M;
        m[A[i]]++;
    }
    for(auto a:m) ans+=a.second*(a.second-1)/2;
    cout<<ans<<endl;
}