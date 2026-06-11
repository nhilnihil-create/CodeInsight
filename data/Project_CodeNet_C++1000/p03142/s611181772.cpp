#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
int main(){
    int n,m;cin >> n >> m;
    vector<int> path[n+1];
    vector<int> h(n+1);
    for(int i=0; i<n-1+m; i++){
        int a,b;cin >> a >> b;
        path[a].push_back(b);
        h[b]++;
    }
    queue<int> q;
    vector<int> par(n+1);
    for(int i=1; i<=n; i++){
        if(h[i]==0){
            q.push(i);
            par[i]=0;
        }
    }
    while(!q.empty()){
        int now=q.front();q.pop();
        for(auto next: path[now]){
            h[next]--;
            if(h[next]==0){
                q.push(next);
                par[next]=now;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << par[i] << endl;
    }
    return 0;
}