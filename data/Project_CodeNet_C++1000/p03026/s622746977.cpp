#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;


int N;
vector<vector<int>> to;
vector<int> ans;
priority_queue<int> c;
int res = 0;

void dfs(int u, int v = -1){
    
    for (int i : to[u]) {
        if(i == v) continue;
        int d = c.top();
        c.pop();
        ans[i] = d;
        res += d;
        dfs(i,u);
    }
    
}



int main()
{
    cin >> N;
    to.resize(N);
    ans.resize(N);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--,b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i,N){
        int cc;
        cin >> cc;
        c.push(cc);
    }
    ans[0] = c.top();
    c.pop();
    dfs(0);
    
    cout << res << endl;
    rep(i,N) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}

