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
    int H,W,N;cin>>H>>W>>N;
    int sr,sc;cin>>sr>>sc;
  sr--;sc--;
    string S,T;cin>>S>>T;
    for(int t=0;t<2;t++){
        int X=(t==0?H:W);
        int st=(t==0?sr:sc);
        int mn=0,mx=X-1;
        char add=(t==0?'D':'R');
        char sub=(t==0?'U':'L');
        for(int i=N-1;i>=0;i--){
            if(T[i]==add) mn=max(0,mn-1);
            else if(T[i]==sub) mx=min(X-1,mx+1);
            if(S[i]==add) mx--;
            else if(S[i]==sub) mn++;
            if(mn<0||mx>=X||mn>mx){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(mn>st||st>mx){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}