#include<iostream>
#include<vector>
using namespace std;

#define pii pair<int, int>
#define ft first
#define sd second

const int N = 1e5+5;
vector<pii> vec[N];
int col[N];

void dfs(int u, int p){
    for(pii x: vec[u]){
        if(x.ft != p){
            if(x.sd%2 == 0){
                col[x.ft] = col[u];
            }
            else{
                col[x.ft] = (col[u] ^ 1);
            }
            dfs(x.ft, u);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v, h;
        cin >> u >> v >> h;
        vec[u].push_back({v, h});
        vec[v].push_back({u, h});
    }
    dfs(1, 0);
    for(int i = 1 ; i<= n; i++)
        cout << col[i] << " ";
}
