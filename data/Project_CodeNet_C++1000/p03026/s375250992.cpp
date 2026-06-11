#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
typedef stack<ll> ST;
typedef queue<ll> QUE;
#define pb push_back
#define st first
#define nd second
#define SZ(x) ((int)(x).size())
#define FOR(i,s,n) for(int i=(int)(s); i< (int)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define each(x,c) for(auto x: (c))
#define LB(x,a) lower_bound(all(x), a)
#define UB(x,a) upper_bound(all(x), a)
const ll mod=1e9+7;
const ll INF=1e18;
const double EPS=1.0e-10;
const double PI=M_PI;

vec c(10010),d(10010);
mat G(10010);
int k=0;
void DFS(int s, int p){
    d[s]=c[k++];
    each(t,G[s]){
        if(t==p) continue;
        DFS(t,s);
    }
    return;
}

int main(){
    int N; cin>>N;
    rep(i,N-1){
        int a,b; cin>>a>>b; a--;b--;
        G[a].pb(b); G[b].pb(a);
    }
    ll ans=0;
    rep(i,N){
        cin>>c[i];
        ans+=c[i];
    }
    sort(all(c),greater<ll>());
    DFS(0,-1);
    ans-=c[0];
    cout<<ans<<endl;
    rep(i,N-1) cout<<d[i]<<" ";
    cout<<d[N-1]<<endl;
    return 0;
}