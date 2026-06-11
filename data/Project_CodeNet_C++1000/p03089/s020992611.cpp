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

int main(){
    int n;cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> ans;
    while(true){
        int m=(int)b.size();
        for(int i=m-1;i>=0;i--){
            if(b[i]==i+1){
                ans.push_back(b[i]);
                b.erase(b.begin()+i);
                break;
            }
            if(b[i]>i+1){
                cout<<-1<<endl;
                return 0;
            }
        }
        if(b.size()==0) break;
    }
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<endl;
    }
    return 0;
}