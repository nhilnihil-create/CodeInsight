#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> h(n),ans(n);
    for(int i=0;i<n+m-1;i++){
        int a,b;cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        h[b]++;
    }
    int r;
    for(int i=0;i<n;i++){
        if(!h[i]){
            r=i;
            break;
        }
    }
    queue<int> q;
    q.push(r);
    ans[r]=0;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int x:g[p]){
            h[x]--;
            if(!h[x]){
                ans[x]=p+1;
                q.push(x);
            }
        }
    }
    for(int x:ans){
        cout << x << endl;
    }
}