#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1000000007;
const long long inf = 1e18;

int visited[51][51];
vector<pair<int,int> > arr[51][51];

void bfs(pair<int,int> x){
    queue<pair<int,int> > q;
    q.push(x);
    visited[x.fi][x.se]=1;
    while(!q.empty()){
        pair<int,int> u=q.front();
        q.pop();
        int a=u.fi;
        int b=u.se;
        for(int i=0;i<arr[a][b].size();i++){
            pair<int,int> node=arr[a][b][i];
            if(visited[node.fi][node.se]==0){
                q.push(node);
                visited[node.fi][node.se]=visited[a][b]+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h,w;
    cin>>h>>w;
    vector<string> s(h+2);
    string k="";
    for(int i=0;i<w+2;i++){
        k="#"+k;
    }
    s[0]=k;
    for(int i=1;i<=h;i++){
        cin>>s[i];
        s[i]="#"+s[i]+"#";
    }
    s[h+1]=k;
    // 1 index 1,1->h,w
    int count=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(s[i][j]=='.'){
                count+=1;
            }
            if(s[i][j]=='.' && s[i][j+1]=='.'){
                arr[i][j].pb(mp(i,j+1));
            }
            if(s[i][j]=='.' && s[i][j-1]=='.'){
                arr[i][j].pb(mp(i,j-1));
            }
            if(s[i][j]=='.' && s[i+1][j]=='.'){
                arr[i][j].pb(mp(i+1,j));
            }
            if(s[i][j]=='.' && s[i-1][j]=='.'){
                arr[i][j].pb(mp(i-1,j));
            }
        }
    }
    bfs(mp(1,1));
    if(visited[h][w]>0)
        cout<<count-visited[h][w]<<endl;
    else{
        cout<<-1<<endl;
    }
    return 0;
}
