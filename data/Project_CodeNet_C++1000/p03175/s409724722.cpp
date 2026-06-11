#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxN = 1e5 + 5, MOD = 1e9 + 7;

vector<vector<int>> eg(maxN);
vector<int> q;
vector<ll> dpw(maxN), dpb(maxN);
bool visited[maxN];

int main() {
    int n, x, y;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        eg[x].push_back(y);
        eg[y].push_back(x);
    }
    q.push_back(1);
    int ci = 0, cn;
    while(q.size() != n) {
        cn = q[ci];
        //cout << "vertices ";
        for(int i = 0; i < eg[cn].size(); i++) {
            if(!visited[eg[cn][i]]) {
                q.push_back(eg[cn][i]);
                //cout << eg[cn][i] << ' ';
            }
        }
        visited[q[ci]] = true;
        ci++;
        //cout << endl << "size " << q.size() << endl;
    }
    //cout << "yyay" << endl;
    fill(visited, visited + n + 1, false);
    for(auto it = q.rbegin(); it != q.rend(); it++) {
        ll mw = 1, mb = 1;
        cn = *it;
        //cout << "visited is "; for(int i = 1; i <= n; i++) cout << visited[i] << ' '; cout << endl; 
        for(int i = 0; i < eg[cn].size(); i++) {
            //cout << eg[cn][i] << endl;
            if(visited[eg[cn][i]]) {
                mw = (mw * (dpw[eg[cn][i]] + dpb[eg[cn][i]]) % MOD) % MOD;
                mb = (mb * dpw[eg[cn][i]]) % MOD;
                //cout << dpw[eg[cn][i]] << ' ' << dpb[eg[cn][i]] << endl;
            }
        }
        dpw[cn] = mw;
        dpb[cn] = mb;
        visited[cn] = true;
        //cout << "current node " << cn << ' ' << dpw[cn] << ' ' << dpb[cn] << endl;
        //cout << "yay" << endl;
    }
    //for(int i = 1; i <= n; i++) cout << dpw[i] << ' ' << dpb[i] << endl;
    cout << (dpw[1] + dpb[1]) % MOD;
    return 0;
}
