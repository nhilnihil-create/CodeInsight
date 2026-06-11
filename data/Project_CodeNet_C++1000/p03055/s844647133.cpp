#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n,l=0;

vector<vector<int>> G;
vector<int> depth;

int dfs(int s,int par){
    if (par!=-1) depth[s]=depth[par]+1;
    vector<int> a={depth[s],depth[s]};
    rep(i,G[s].size()){
        int t=G[s][i];
        if (t==par) continue;
        a.push_back(dfs(t,s));
    }
    sort(a.begin(),a.end(),greater<int>());
    l=max(l,a[0]+a[1]-2*depth[s]);
    return a[0];
}

void solve(){
    cin >> n;
    G.resize(n,{});depth.resize(n,0);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    dfs(0,-1);
    
    if (l%3==1) cout << "Second" << endl;
    else cout << "First" << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}