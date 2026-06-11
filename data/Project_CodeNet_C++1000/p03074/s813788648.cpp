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
    ll N,K,cnt=0;
    string S;
    pair<ll,ll> P;
    P.first=1;
    P.second=0;
    cin>>N>>K>>S;
    vector<pair<ll,ll>> v;
    if(S[0]=='0') v.push_back(P);
    for(ll i=0;i<N;i++){
        pair<ll,ll> p;
        ll cnt=1;
        if(S[i]=='0'){
            while(i+1<N&&S[i+1]=='0'){
                cnt++;
                i++;
            }
            p.first=0;
            p.second=cnt;
        }else{
            while(i+1<N&&S[i+1]=='1'){
                cnt++;
                i++;
            }
            p.first=1;
            p.second=cnt;
        }
        v.push_back(p);
    }
    
    if(v[v.size()-1].first==0) v.push_back(P);

    for(ll i=1;i<v.size();i++) v[i].second+=v[i-1].second;
    if(v.size()<K*2){
        cout<<v[v.size()-1].second<<endl;
        return 0;
    }
    ll ans=v[K*2].second;
    for(ll i=K*2+2;i<v.size();i+=2){
        chmax(ans,v[i].second-v[i-K*2-1].second);
    }
    cout<<ans<<endl;
}
