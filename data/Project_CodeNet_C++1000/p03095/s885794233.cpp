#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=100100;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,ans=1;
    string S;
    cin>>N>>S;
    map<char,ll> m;
    for(ll i=0;i<N;i++) m[S[i]]++;
    sort(S.begin(),S.end());
    for(ll i=0;i<N;i++){
        ans*=m[S[i]]+1;
        i+=m[S[i]]-1;
        ans%=MOD;
    }
    ans=(ans-1)%MOD;
    cout<<ans<<endl;
}
