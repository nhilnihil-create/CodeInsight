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

vector<int> v[404040];
int used[404040],ans;

void dfs(int x){
    used[x]=-1;
    for(auto& u:v[x]){
        if(used[u]==-1){
            ans=true;
        }
        else if(used[u]==1)continue;
        else dfs(u);
    }
    used[x]=1;
}
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        if(s[x]==s[y]){
            v[x].push_back(y+n);
            v[y].push_back(x+n);
        }
        else {
            v[x+n].push_back(y);
            v[y+n].push_back(x);
        }
    }
    rep(i,2*n)if(!used[i])dfs(i);
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}