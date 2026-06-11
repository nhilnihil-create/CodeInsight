#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int a[m];
    int b[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    int count=0;
    for(int skip = 0; skip < m; skip++) {
//        cout << "skip : " << skip << "\n";
        vector<vector<int>> g(n);
        for(int i = 0; i < m; i++) {
            if(i!=skip){
                int ta=a[i]-1;
                int tb=b[i]-1;
                g[ta].emplace_back(tb);
                g[tb].emplace_back(ta);
            }
        }

        vector<int> dist(n, -1);
        queue<int> que;

        dist[0] = 0;
        que.push(0);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int nv : g[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }

        bool jud=true;
        for(int i = 0; i < n; i++) {
            if(dist[i]==-1) jud=false;
        }
        if(jud==false) count++;
    }
    cout << count << "\n";
    return 0;
}