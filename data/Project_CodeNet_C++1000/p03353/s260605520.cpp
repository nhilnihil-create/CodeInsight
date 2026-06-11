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

int main(){
    string s;cin>>s;
    int k;cin>>k;
    int n=(int)s.size();
    set<string> ans;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k&&j<=n-i;j++){
            ans.insert(s.substr(i,j));
        }
    }
    auto it=ans.begin();
  for(int i=1;i<k;i++) it++;
    cout<<*it<<endl;
    return 0;
}