#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=1e18;

int n,m;
vector<ll> x(1000),y(1000),z(1000);
ll solve(int a,int b,int c){
    vector<ll> res(n);
    for(int i=0;i<n;i++){
        res[i]=x[i]*(a?1:-1)+y[i]*(b?1:-1)+z[i]*(c?1:-1);
    }
    sort(res.begin(),res.end(),greater<ll>());
    ll sum=0;
    for(int i=0;i<m;i++) sum+=res[i];
    return sum;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>z[i];
    ll ans=0;
    for(int b=0;b<(1<<3);b++){
        ans=max(ans,solve((b&1),((b>>1)&1),((b>>2)&1)));
    }
    cout<<ans<<endl;
    return 0;
}