#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> edge[n+1];
    vector<int> redge[n+1];
    int cnt[n+1];
    fill(cnt,cnt+n+1,0);
    for(int i=0; i<n+m-1; i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        redge[b].push_back(a);
        cnt[b]++;
    }
    queue<int> s;
    for(int i=1; i<n+1; i++){
        if(cnt[i]==0) s.push(i);
    }
    vector<int> vec;
    int rvec[n+1];
    rvec[0] = -1;
    while(!s.empty()){
        int u = s.front();
        s.pop();
        vec.push_back(u);
        rvec[u] = vec.size();
        for(int i=0; i<edge[u].size(); i++){
            cnt[edge[u][i]]--;
            if(cnt[edge[u][i]] == 0) s.push(edge[u][i]);
        }
    }
    int ans[n+1];
    ans[vec[0]] = 0;
    for(int i=1; i<vec.size(); i++){
        int a = vec[i];
        int t = 0;
        for(int j=0; j<redge[a].size(); j++){
            int k = redge[a][j];
            if(rvec[k] > rvec[t]) t = k;
        }
        ans[a] = t;
    }
    for(int i=1; i<n+1; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
