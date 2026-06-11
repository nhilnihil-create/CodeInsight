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
    vector<ll> l(N,0);
    vector<ll> r(N,0);
    for(ll i=0;i<N;i++)
    cin>>l[i]>>r[i];
    multiset<P> L;//P(L,R)後ろから取り出す
    multiset<P> R;//P(R,L)前から取り出す
    for(ll i=0;i<N;i++){
        L.insert(P(l[i],r[i]));
        R.insert(P(r[i],l[i]));
    }
    multiset<P> L2=L;//P(L,R)後ろから取り出す
    multiset<P> R2=R;//P(R,L)前から取り出す
    ll ans=0;
    ll now=0;
    while(1){
        if(L.empty())break;
        P x=*prev(L.end());
        if(x.first<=now)break;
        ans+=x.first-now;
        now=x.first;
        L.erase(prev(L.end()));
        R.erase(R.lower_bound(P(x.second,x.first)));

        if(R.empty())break;
        x=*R.begin();
        if(x.first>=now)break;
        ans+=now-x.first;
        now=x.first;
        R.erase(R.begin());
        L.erase(L.lower_bound(P(x.second,x.first)));

    }
    ans+=llabs(now);

    ll ans2=0;
    now=0;
    while(1){
        if(R2.empty())break;
        P x=*R2.begin();
        if(x.first>=now)break;
        ans2+=now-x.first;
        now=x.first;
        R2.erase(R2.begin());
        L2.erase(L2.lower_bound(P(x.second,x.first)));

        if(L2.empty())break;
        x=*prev(L2.end());
        if(x.first<=now)break;
        ans2+=x.first-now;
        now=x.first;
        L2.erase(prev(L2.end()));
        R2.erase(R2.lower_bound(P(x.second,x.first)));

    }
    ans2+=llabs(now);
    print(max(ans,ans2))
    
    return 0;
}
