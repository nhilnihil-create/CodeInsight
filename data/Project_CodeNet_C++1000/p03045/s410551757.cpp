#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};
ll N,M;
vector<vector<ll> > G;
vector<bool> seen;
void dfs(ll v){
    seen[v] = 1;

    rep(i,G[v].size()){
        if(seen[G[v][i]] == 0){
            dfs(G[v][i]);
        }
    }

}

int main() {
    
    cin >>N>>M;
    vector<bool>m(N);
    G.resize(N);
    seen.resize(N);
    ll ans = 0;
    rep(i,M){
        ll x,y,z;
        cin>>x>>y>>z;
        x--;y--;
        G[x].pb(y);
        G[y].pb(x);
    }

    rep(i,N){
        if(seen[i]==0){
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;


    return 0;
    

}