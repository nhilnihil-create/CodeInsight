#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n), rG(n);
    vector<int> out(n);
    for(int i=0; i<n+m-1; i++) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        rG[b].push_back(a);
        out[a]++;
    }

    vector<int> ord(n);
    {
        int x = 0;
        queue<int> q;
        for(int i=0; i<n; i++)
            if(out[i] == 0) q.push(i);

        while(!q.empty()) {
            int v = q.front(); q.pop();
            ord[v] = ++x;
            for(auto &i: rG[v])
                if(--out[i] == 0) q.push(i);
        }
    }

    for(int i=0; i<n; i++) {
        int r = 0, mx = 1e9;
        for(auto &j: rG[i])
            if(ord[j] < mx)
                r = j+1, mx = ord[j];
        cout << r << endl;
    }
}
