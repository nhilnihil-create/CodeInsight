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
    ll Q;
    cin >> Q;
    string S;
    cin >> S;
    vector<ll> l(Q,0);
    vector<ll> r(Q,0);
    for(ll i=0;i<Q;i++){cin>>l[i]>>r[i];l[i]--;r[i]--;}
    vector<ll> until(N,0);
    for(ll i=1;i<N;i++){
        until[i]=until[i-1];
        if(S[i-1]=='A'&&S[i]=='C')until[i]++;
        //print(until[i])
    }
    for(ll i=0;i<Q;i++){
        if(l[i]==0){
            print(until[r[i]])
            continue;
        }
        ll ans=until[r[i]]-until[l[i]-1];
        if(S[l[i]-1]=='A'&&S[l[i]]=='C')ans--;
        print(ans);
    }
    return 0;
}