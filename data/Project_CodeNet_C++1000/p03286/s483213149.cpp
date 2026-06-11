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
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=1e9;
const ll MOD=1e9+7;

int N;
vector<int> a,b;
vector<vector<int> > G;
ll solve(int u,int c,int p){
    if(G[u].size()==1) return 1;
    ll res=0;
    for(auto v:G[u]){
        if(v==p) continue;
        if(c==1) res=(res+solve(v,0,u))%MOD;
        res=(res+solve(v,0,u))%MOD;
    }
    return res%MOD;
}
int main(){
    int N;cin>>N;
    if(N==0){
        cout<<0<<endl;
        return 0;
    }
    vector<int> ans;
    while(N!=0){
        int r=(abs(N)%2==1?1:0);
        N=(N-r)/(-2);
        ans.push_back(r);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();++i) cout<<ans[i];
    cout<<endl;
    return 0;
}