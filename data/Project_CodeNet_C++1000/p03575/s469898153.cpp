#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

vector<pair<int,int>> to;
vector<bool> seen(50,false);
vector<vector<int>> go(50);
int cnt = 0;

void dfs(int a,int p = -1){
    if(seen[a]) return;
    seen[a] = true;
    for(auto r:go[a]){
        if(r == p) continue;
        if(to[cnt] == make_pair(min(a,r),max(a,r))) continue;
        dfs(r,a);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to.push_back(make_pair(a,b));
        go[a].push_back(b);
        go[b].push_back(a);
    } 
    for(int i = 0; i < m; i++){
        bool flag = false;
        cnt = i;
        dfs(0);
        for(int j = 0; j < n; j++){
            if(!seen[j]) flag = true;
            else seen[j] = false;
        }
        if(flag) ans++;
    }
    cout << ans << endl;
}