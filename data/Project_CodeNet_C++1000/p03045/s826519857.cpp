#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;

vector<int> to[100010];
vector<bool> und(1000010,0);
int now;

void dfs(int x){
    for(auto u : to[x]){
        if(und[u]==0){
            now++;
            und[u]=1;
            dfs(u);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int x;
        int y;
        int dumy;
        cin >> x >> y>>dumy;
        x--;y--;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    int ans = 0;
    while(1){
        rep(i,n){
            if(und[i]==0){
                ans++;
                und[i]=1;
                dfs(i);
            }
        }
        bool ok = 1;
        rep(i,n){
            if(und[i]==0) ok = 0;
        }
        if(ok) break;
    }
    cout<<ans<<endl;
    return 0;
}