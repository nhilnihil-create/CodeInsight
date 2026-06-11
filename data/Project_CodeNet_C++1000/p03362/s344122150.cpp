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

vector<ll> v(55556,1);
vector<ll> ans;

int main(){
    ll N;
    cin>>N;
    set<ll> s;
    v[0]=0;
    v[1]=0;
    for(ll i=2;i<v.size();i++){
        if(v[i]==0) continue;
        else{
            for(ll j=2;i*j<v.size();j++) v[i*j]=0;
        }
    }
    for(ll i=0;i<v.size();i++){
        if(v[i]==1&&i%5==1){
            ans.push_back(i);
        }
    }
    for(ll i=0;i<N;i++){
        cout<<ans[i];
        if(i!=N-1) cout<<" ";
    }
    cout<<endl;
}