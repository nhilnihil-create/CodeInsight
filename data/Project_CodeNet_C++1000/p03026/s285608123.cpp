
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<ll,ll> ;
const ll INF = 1e18;
const int MOD = 1000000007;
int n = 10005;
vector<vector<int>> tree(n,vector<int>());
vector<int> c(n);
vector<int> ans(n);
int cnt = 0;
int M = 0;

void dfs(int i,int p=-1){
    for(int child:tree[i]){
        if(child==p) continue;
        dfs(child,i);
    }

    ans[i] = c[cnt];
    if(cnt != n-1) M += ans[i];
    ++cnt;
    return;
}

int main(){
    cin >> n;
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    c.resize(n);
    rep(i,n) cin >> c[i];
    sort(c.begin(),c.end());
    dfs(0);
    cout << M << endl;
    rep(i,n){
        cout << ans[i] << (i==n-1 ? '\n' : ' ');
    } 
    return 0;
}