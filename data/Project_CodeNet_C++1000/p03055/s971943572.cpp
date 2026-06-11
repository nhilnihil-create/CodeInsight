#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define mod 1000000007
using namespace std;
typedef long long ll;
bool chmax(ll &a,ll b){
    if(a>b)return 0;
    a=b; return 1;
}
bool chmin(ll &a,ll b){
    if(a<b)return 0;
    a=b; return 1;
}
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

ll n;
vector<ll> g[200010];
ll ma,pnt;
void dfs(ll x,ll from,ll d){
    if(d>=ma)ma=d,pnt=x;
    for(auto y:g[x])if(y!=from){
	dfs(y,x,d+1);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
	ll a,b; cin>>a>>b;
	g[a].push_back(b);
	g[b].push_back(a);
    }
    ma=-1;
    dfs(1,0,0);
    dfs(pnt,0,0);
    if(ma%3!=1)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}


