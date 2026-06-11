#include<bits/stdc++.h>
using namespace std;

static const int INF=1e9;
static const int MOD=1000000007;
typedef long long ll;
typedef pair<int,int> P;

vector<int> g[10100];
int ans[10100];
int c[10100];
int tmp=1;

void solve(int u,int pa=-1){
    for(auto v:g[u]){
        if(v==pa) continue;
        ans[v]=c[tmp];
        tmp++;
        solve(v,u);
    }
}

int main(){
    int N; cin >> N;
    int f[N]={};
    for(int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        f[a]++;f[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<N;i++){
        cin >> c[i];
    }
    sort(c,c+N,greater<int>());
    int M=0;
    for(int i=1;i<N;i++){
        M+=c[i];
    }
    ans[0]=c[0];
    solve(0);
    cout << M << endl;
    for(int i=0;i<N;i++){
        cout << ans[i] << endl;
    }
}
