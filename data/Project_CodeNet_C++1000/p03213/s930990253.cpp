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
const ll INF=2e18;

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

int f(int x){
    if(x==0) return 1;
    return f(x%popcount(x))+1;
}

vector<int> prime_factor(int n){
    vector<int> res(n+1,0);
    for(int i=2;i<=n;i++){
        int m=i;
        for(int j=2;j*j<=m;j++){
            if(m%j==0){
                while(m%j==0){
                    res[j]++;
                    m/=j;
                }
            }
        }
        if(m!=1) res[m]++;
    }
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> cp=prime_factor(n);
    int ans=0;
    sort(cp.begin(),cp.end(),greater<int>());
    int m=(int)cp.size();
    for(int i=0;i<m;i++){
        if(cp[i]>=74) ans++;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j) continue;
            if(cp[i]>=24&&cp[j]>=2) ans++;
            if(cp[i]>=14&&cp[j]>=4) ans++;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k=0;k<m;k++){
                if(i==j||j==k||k==i) continue;
                if(cp[i]>=4&&cp[j]>=4&&cp[k]>=2) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}