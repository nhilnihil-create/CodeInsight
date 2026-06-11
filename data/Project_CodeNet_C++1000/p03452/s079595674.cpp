#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1<<30;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};

vector<int> par(0);
vector<int> depth(0);
vector<int> heavy(0);
void init(int n){
   par.resize(n);
   depth.resize(n,0);
   heavy.resize(n,0);
   rep(i,n) par[i]=i;
}

int find(int x){
   if(par[x]==x) return x;
   int parent =find(par[x]);
   heavy[x]+=heavy[par[x]];
   return par[x]=parent;
}

int wei(int x){
   find(x);
   return heavy[x];
}

void unite(int x,int y,int z){//yはxよりz重い
   z +=wei(x)-wei(y);
   x=find(x);
   y=find(y);
   if(par[x]==par[y]) return;
   if(depth[x]<depth[y]){
      par[x]=y;
      heavy[x]=-z;
   }
   else{
      par[y]=x;
      heavy[y]=z;
   if(depth[x]==depth[y]) depth[x] ++;
   }
}

bool same(int x,int y){
   return find(x)==find(y);
}

int diff(int x,int y){//w[y]-w[x],比較不可なら-1
   if(!same(x,y)) return -1;
   return wei(y)-wei(x);
}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n,m,l,r,d;
    cin>>n>>m;
    init(n);
    rep(i,m){
        cin>>l>>r>>d;
        r --;
        l --;
        if(diff(l,r)==d) continue;
        else if(same(l,r)){
            cout<<"No"<<endl;
            return 0;
        }
        else unite(l,r,d);
    }
    cout<<"Yes"<<endl;
}