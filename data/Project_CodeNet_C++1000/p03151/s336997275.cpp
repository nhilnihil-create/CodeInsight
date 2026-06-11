#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
//vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }
bool com(ll a,ll b,ll M){
    return abs(M-a)<abs(M-b);
}

int main(){
    ll N,sumA=0,sumB=0,hu=0,ans=0;
    cin>>N;
    ll A[N],B[N],v[N];
    for(ll i=0;i<N;i++){
        cin>>A[i];
        sumA+=A[i];
    }
    for(ll i=0;i<N;i++){
        cin>>B[i];
        sumB+=B[i];
        v[i]=A[i]-B[i];
        if(v[i]<0){
            hu+=v[i];
            ans++;
        }
    }
    if(sumA<sumB){
        cout<<"-1"<<endl;
        return 0;
    }
    sort(v,v+N);
    for(ll i=N-1;i>=0;i--){
        if(hu>=0) break;
        if(v[i]<0) continue;
        hu+=v[i];
        ans++;
    }
    cout<<ans<<endl;
}
