#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;



signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n=s.size();
    string t=s.substr(0,n-1);
    if(s[n-1]!='0'){
        prt(-1)return 0;
    }
    string u=t;
    reverse(u.begin(), u.end());
    if(u!=t){
        prt(-1)return 0;
    }
    if(u[0]!='1'){
        prt(-1)return 0;
    }
    vector<P> ans(0);
    ll root=2;
    ans.emplace_back(P(1,2));
    for(ll i=1;i<=n-2;++i){
        if(t[i]=='1'){
            ans.emplace_back(P(root,i+2));
            root=i+2;
        }else {
            ans.emplace_back(P(root,i+2));
        }
    }
    for(auto p: ans){
        cout<<p.first<<" "<<p.second<<endl;
    }fl

    
    return 0;
}
