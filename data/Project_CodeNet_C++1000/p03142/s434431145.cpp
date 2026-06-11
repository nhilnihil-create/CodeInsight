#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> v(100010);
int cnt[100010];
int used[100010];
int ans[100010];
queue<int> q;

void bfs(int p){
    for(auto i:v[p]){
        used[i]++;
        if(used[i] == cnt[i]){
            q.push(i);
            ans[i] = p+1;
        }
    }
    if(!q.empty()){
        int next = q.front();
        q.pop();
        bfs(next);
    }
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin>>n>>m;
    int s[n+m-1],t[n+m-1];
    for(int i=0;i<n+m-1;i++){
        int a,b; cin>>a>>b;
        a--,b--;
        s[i] = a, t[i] = b;
        cnt[b]++;
        v[a].push_back(b);
    }
    int root;
    for(int i=0;i<n;i++){
        if(cnt[i] == 0){
            root = i;
            break;
        }
    }
    bfs(root);

    for(int i=0;i<n;i++){
        cout << ans[i] << "\n";
    }
    
    
}