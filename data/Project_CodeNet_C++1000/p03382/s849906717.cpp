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
    ll N,M,m,ans;
    cin>>N;
    ll A[N];
    for(ll i=0;i<N;i++) cin>>A[i];
    sort(A,A+N);
    M=A[N-1];
    A[N-1]=A[0];
    ans=A[0];
    for(ll i=0;i<N;i++){
        if(ans<min(M-A[i],A[i])){
            ans=A[i];
        }
    }
    cout<<M<<" "<<ans<<endl;

}
