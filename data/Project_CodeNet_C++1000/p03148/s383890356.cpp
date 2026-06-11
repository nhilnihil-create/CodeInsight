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
    ll K;
    cin >> K;
    vector<ll> t(N,0);
    vector<ll> d(N,0);
    for(ll i=0;i<N;i++)cin>>t[i]>>d[i];
    priority_queue<P> pq;
    for(ll i=0;i<N;i++)pq.emplace(P(d[i],t[i]));
    vector<ll> cho(0);
    vector<ll> ncho(0);
    vector<bool> check(N+1,0);
    ll sum=0;ll pat=0;
       /* cout<<"ここから"<<endl;
    while(pq.size()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }return 0;*/
    for(ll i=0;i<K;i++){
        P x=pq.top();
        sum+=x.first;
        if(check[x.second]){
            cho.emplace_back(x.first);
        }
        else pat++;
        check[x.second]=1;
        pq.pop();
    }
    while(!pq.empty()){
        P x=pq.top();
        if(!check[x.second]){
            ncho.emplace_back(x.first);
        }
        check[x.second]=1;
        pq.pop();
    }
    ll D=min(cho.size(),ncho.size());
    reverse(cho.begin(), cho.end());
    ll ans=sum+pat*pat;
    for(ll i=0;i<D;i++){
        sum-=cho[i];
        sum+=ncho[i];
        chmax(ans,sum+(pat+i+1)*(pat+i+1));
    }
    print(ans)
    return 0;
}