#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
using namespace std;

int N,M; vector<int> a,b;
void input()
{
    cin >> N >> M;
    a.resize(M), b.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
}

void solve()
{
    
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        vector<vector<int>> G(N);
        for (int j = 0; j < M; ++j){
            if(i==j) continue;
            G[a[j]].emplace_back(b[j]);
            G[b[j]].emplace_back(a[j]);
        }

        vector<bool> is_checked(N,false);
        queue<int> que; que.push(0);
        while(!que.empty()){
            int v = que.front(); que.pop();
            is_checked[v] = true;
            for (auto nv: G[v]){
                if(is_checked[nv]) continue;
                que.push(nv);
            }
        }

        for(auto is: is_checked){
            if(!is){
                ++ans; break;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}