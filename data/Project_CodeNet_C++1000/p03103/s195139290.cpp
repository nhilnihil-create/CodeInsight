#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<P,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> A(N,0);
    vector<ll> B(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    for(ll i=0;i<N;i++)pq.emplace(P(A[i],B[i]));
    ll nokori=M;
    ll ans=0;
    while(nokori>0){
        P x=pq.top();
        pq.pop();
        if(nokori>=x.second){
            ans+=x.second*x.first;
            nokori-=x.second;
        }
        else {
            ans+=x.first*nokori;
            nokori=0;
            break;
        }
    }
    print(ans)
    return 0;
}