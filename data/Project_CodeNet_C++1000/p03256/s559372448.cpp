#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int n,m;
vector<int> used,cmp,vs;
vector<vector<int>> v,rv;

void addedge(int x,int y){
    v[x].push_back(y);
    rv[y].push_back(x);
}
void dfs(int x){
   used[x]=true;
   for(auto to:v[x])if(!used[to])dfs(to);
   vs.push_back(x);
}

void rdfs(int x,int k){
   used[x]=true;
   cmp[x]=k;
   for(auto to:rv[x])if(!used[to])rdfs(to,k);
}

int scc(){
   used.resize(n);
   cmp.resize(n);
   rep(i,n)if(!used[i])dfs(i);
   rep(i,n)used[i]=0;
   reverse(vs.begin(),vs.end());
   int k=0;
   for(auto x:vs)if(!used[x])rdfs(x,k++);
   return k;
}
int main(){
    cin>>n>>m;
    string s;
    cin>>s;
    v.resize(2*n);
    rv.resize(2*n);
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        if(s[x]==s[y]){
            addedge(x,y+n);
            addedge(y,x+n);
        }
        else {
            addedge(x+n,y);
            addedge(y+n,x);
        }
    }
    n*=2;

    cout<<(scc()==n?"No":"Yes")<<endl;
    return 0;
}