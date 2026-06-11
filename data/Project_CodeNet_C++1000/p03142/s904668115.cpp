#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;

vector<ll> G[MAX];
list<ll> out;
bool V[MAX];
ll N;
ll indeg[MAX];
ll ans[MAX];

void bfs(ll s){
    queue<ll> q;
    q.push(s);
    V[s]=true;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        out.push_back(u);
        for(ll i=0;i<G[u].size();i++){
            ll v=G[u][i];
            indeg[v]--;
            if(indeg[v]==0 && !V[v]){
                ans[v]=u;
                V[v]=true;
                q.push(v);
            }
        }
    }
}

void  tsort(){
    for(ll i=0;i<N;i++){
        indeg[i]=0;
    }
    for(ll u=0;u<N;u++){
        for(ll i=0;i<G[u].size();i++){
            ll v= G[u][i];
            indeg[v]++;
        }
    }

    for(ll u=0;u<N;u++){
        if(indeg[u]==0 && !V[u]){
            ans[u]=-1;
            bfs(u);
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M;
    cin>>N>>M;
    rep(i,N+M-1){
        ll s,t;
        cin>>s>>t;
        s--;t--;
        G[s].pb(t);
    }
    tsort();
    rep(i,N){
        cout<<ans[i]+1<<endl;
    }
    return 0;
}