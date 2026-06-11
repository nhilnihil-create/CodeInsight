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
const ll INF=2e9;

struct UnionFindTree{
    vector<int> par,rank;
    UnionFindTree(int n):par(n),rank(n,0){
        for(int i=0;i<n;i++) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[rx]<rank[ry]) par[rx]=ry;
        else par[ry]=rx;
        if(rank[rx]==rank[ry]) rank[rx]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
};

ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res*=a;
        a*=a;
        x>>=1;
    }
    return res;
}

int popcount(int x){
    int res=0;
    while(x>0){
        if(x&1) res++;
        x>>=1;
    }
    return res;
}

ll f(ll x){
    ll res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> C(n);
    for(int i=0;i<n;i++) cin>>C[i];
    vector<ll> DP(n+1,0),L(200001,-1);
    DP[0]=1;
    for(int i=0;i<n;i++){
        DP[i+1]=DP[i];
        int c=C[i];
        if(L[c]>=0&&L[c]<i-1){
          DP[i+1]=(DP[i+1]+DP[L[c]+1])%MOD;
        }
        L[c]=i;
    }
    cout<<DP[n]<<endl;
    return 0;
}