#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>bool chmax(T &a, const T &b) { if (a<=b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<=a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n,k;
    cin>>n>>k;
    map<int,priority_queue<ll>> mp;
    rep(i,n) {
        int t;
        ll d;
        cin>>t>>d;
        mp[t].push(d);
    }
    
    priority_queue<ll> nokori;
    vector<ll> vec;
    for(auto &p:mp) {
        auto &q=p.second;
        vec.push_back(q.top());
        q.pop();
        while(sz(q)) {
            nokori.push(q.top());
            q.pop();
        }
    }
    
    sort(all(vec),greater<ll>());
    while(sz(vec)>k) {
        vec.pop_back();
    }
    reverse(all(vec));
    
    
    ll ans=0;
    for(ll x:vec) {
        ans+=x;
        //cout<<x<<endl;
    }
    rep(i,k-sz(vec)) {
        if(!sz(nokori)) continue;
        ans+=nokori.top();
        nokori.pop();
    }
    
    ll m=(ll)sz(vec);
    ans+=m*m;
    for(ll x:vec) {
        if(sz(nokori) && -x-m*m+(m-1)*(m-1)+nokori.top()>0) {
            ans+=-x-m*m+(m-1)*(m-1)+nokori.top();
            nokori.pop();
            m--;
        }
    }
    cout<<ans<<endl;
}
