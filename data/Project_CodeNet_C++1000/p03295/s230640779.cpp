#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
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
    vector<ll> A(M,0);
    vector<ll> B(M,0);
    for(ll i=0;i<M;i++)cin>>A[i]>>B[i];
    priority_queue<P, vector<P>, greater<P>> pq;
    for(ll i=0;i<M;i++)pq.emplace(P(B[i],A[i]));
    vector<ll> check(N,0);//check[i]はiとi+1間について
    ll ans=0;
    ll last=-INF;
    while(!pq.empty()){
        P y=pq.top();
        pq.pop();
        if(last<y.second){
            ans++;
            last=y.first-1;
        }
    }
    print(ans)

    return 0;
}