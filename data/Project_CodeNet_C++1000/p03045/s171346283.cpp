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
vector<bool> kn(100010);

void bfs(int i,int p){
    for(auto u : to[i]){
        if(kn[u]==0 && u!=p){
            kn[u] = 1;
            bfs(u,i);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int x,y;
        int dummy;
        cin >> x >> y >> dummy;
        x--; y--;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    int ans = 0;
    rep(i,n){
        if(kn[i]==0){
            ans++;
            kn[i] = 0;
            bfs(i,-1);
        }
    }
    cout << ans << endl;
    return 0;
}