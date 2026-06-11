#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 100000000
#define INF 300000000000000000
#define MOD 1000000007
#define mod 1000000007
#define INT_MAX_ 2147483647
#define REP(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
#define me memset
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[5]={-1,0,1,0,0};
int dy[5]={0,-1,0,1,0};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp1(pair<ll,ll>a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------
bool color[100010];
V<ll>G[100010];
//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_time=clock();
    //-------------------------------
    ll n,m;cin>>n>>m;
    V<ll>p(n);
    for(ll i=0;i<n;i++)cin>>p[i];
    for(ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        x--;y--;
        G[x].pb(y);
        G[y].pb(x);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(color[i]==0){
            color[i]=1;
            V<Pll>use;
            use.pb(mp(i,p[i]));
            queue<ll>Q;
            Q.push(i);
            while(!Q.empty()){
                ll now=Q.front();Q.pop();
                for(ll j=0;j<G[now].size();j++){
                    if(color[G[now][j]])continue;
                    color[G[now][j]]=1;
                    use.pb(mp(G[now][j],p[G[now][j]]));
                    //cout<<G[now][j]<<" "<<p[G[now][j]]<<endl;
                    Q.push(G[now][j]);
                }
            }
            map<ll,ll>M;
            //cout<<use.size()<<endl;
            for(ll j=0;j<use.size();j++){
                M[use[j].fi+1]++;
                M[use[j].se]++;
                //cout<<use[i].fi<<" "<<use[i].se<<endl;
            }
            for(auto it=M.begin();it!=M.end();it++){
                if((it->se)>=2){
                    ans++;
                    //cout<<(it->fi)<<endl;
                }
            }
        }
    }
    cout<<ans<<endl;
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------



































