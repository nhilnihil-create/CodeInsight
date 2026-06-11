#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

typedef struct{
    int to, len;
} edge;
int n, ans[100100];
vector<edge> G[100100];
bool flg[100100];
void nya(int n){
    flg[n] = true;
    for(auto i : G[n]){
        if(!flg[i.to]){
            ans[i.to] = ans[n] ^ i.len;
            nya(i.to);
        }
    }
}
int main(){
    cin >> n;
    rep(i, n)if(i){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edge tmp;
        tmp.to = v; tmp.len = w&1;
        G[u].push_back(tmp);
        tmp.to = u;
        G[v].push_back(tmp);
    }
    ans[0] = 0;
    nya(0);
    rep(i, n)cout << ans[i] << endl;
    return 0;
}