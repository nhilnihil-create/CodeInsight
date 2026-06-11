#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using Tu = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    string S;
    cin >> S;
    deque<ll> deq;
    ll mark=0;
    for(ll i=1;i<N;i++){
        if(S[i-1]!=S[i]){
            deq.emplace_back(i-mark);
            mark=i;
        }
    ;}
    deq.emplace_back(N-mark);
    if(deq.size()<=2*K){
        cout<<N<<endl;return 0;
    }
    ll f=S[0]-'0';
    ll t=deq.size();
    ll sum=0;
    for(ll i=0;i<2*K;i++){
        sum+=deq[i]
    ;}
    ll ans=sum;
    ll g;
    for(ll i=2*K;i<t;i++){
        sum-=deq[i-2*K];
        sum+=deq[i];
        if(i%2!=f)g=deq[i-2*K];
        else g=0;
        ans=max(ans,sum+g);
    ;}
    cout<<ans<<endl;


    return 0;
}
