#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector< vector< int > > edg(n, vector<int>());
    vector<int> deg(n, 0), tp(n, 0), ans(n, 0);
    for(int i=0;i<n-1+m;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edg[a].push_back(b);
        deg[b]++;
    }
    
    queue<int> q;
    for(int i=0;i<n;i++) if(deg[i] == 0) q.push(i);
    int cnt = 0;
    tp.assign(n, 0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        tp[cnt++] = v;
        for(int x : edg[v]){
            if(--deg[x] == 0) q.push(x);
        }
    }
    
    for(int i=0;i<n;i++){
        int v = tp[i];
        for(int x : edg[v]){
            ans[x] = v+1;
        }
    }
    
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
	return 0;
}