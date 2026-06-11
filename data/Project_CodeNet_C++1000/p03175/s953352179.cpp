#include <vector>
#include <iostream>
using namespace std;
#define ll long long
vector<int> adj[100001];
ll ans[100001][2];
ll MOD = 1000000007;
void dfs(int i,int par){
    ll prodW = 1;
    ll prodTot = 1;
    for(int next : adj[i]){
        if(next!=par){
            dfs(next,i);
            prodW*=ans[next][0];
            prodTot*=(ans[next][0]+ans[next][1]);
            prodW%=MOD;
            prodTot%=MOD;
        }
    }
    ans[i][1] = prodW;
    ans[i][0] = prodTot;
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0,-1);
    ll ret = ans[0][0]+ans[0][1];
    ret%=MOD;
    cout << ret << endl;

}
