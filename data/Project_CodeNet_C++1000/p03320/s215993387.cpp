#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tu = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl
#define first(v) get<0>(v)
#define second(v) get<1>(v)
#define third(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

ll S(ll x){
    string y=to_string(x);
    ll n=y.size();
    ll rec=0;
    for(ll i=0;i<n;i++){
        ll j=y[i]-'0';
        rec+=j;
    ;}
    return rec;
}

int main(){
    set<string> Se;
    for(ll i=0;i<=16;i++){
        for(ll j=0;j<100||(j<1000&&i<=15);j++){
            string ret="";
            if(j>0)ret=to_string(j);   
            for(ll k=0;k<i;k++){
                ret+='9';
            ;}
            if(ret=="")ret="0";
            Se.insert(ret);
        ;}
    ;}
    priority_queue<ll, vector<ll>, greater<ll>>  ans;
    priority_queue<ll> once;
    ll n=Se.size();
    auto x=Se.begin();
    for(ll i=0;i<n;i++){
        string f=*x;
        ll e=stoll(f);++x;
        once.emplace(e);
    ;}
    ll R=INF,L=1;
    
    while(!once.empty()){
        ll e=once.top();
        once.pop();
        ll h=S(e);
        if(R*h>=L*e){
            ans.emplace(e);
            R=e,L=h;
        }
    }
    ll K;
    cin >> K;
    ans.pop();
    for(ll i=1;i<=K;i++){
        print(ans.top());
        ans.pop();
    ;}

    return 0;
}
