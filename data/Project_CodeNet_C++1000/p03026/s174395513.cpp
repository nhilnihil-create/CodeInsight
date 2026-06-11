#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

vector<int> edge[10005];
int n;
vector<int>ans;
vector<int> c;
 
int main(void){ 
    cin>>n;
    rep(i, n-1){
        int a, b;
        cin>>a>>b;
        --a;--b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    c.resize(n);
    ans.resize(n);
    rep(i, n) cin>>c[i];
    sort(c.begin(), c.end(), greater<int>());
    priority_queue<int> que;
    que.push(0);
    rep(i, n) ans[i] = -1;
    int idx = 0;
    ans[0] = c[0];
    while(!que.empty()){
        int u = que.top();que.pop();
        //cout<<u<<" "<<idx<<endl;
        for(auto v : edge[u]){
            if(ans[v] != -1) continue;
            idx++;
            ans[v] = c[idx];
            que.push(v);
        }
    }
    int res = accumulate(c.begin(), c.end(), 0);
    res -= c[0];
    cout<<res<<endl;
    rep(i, n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}