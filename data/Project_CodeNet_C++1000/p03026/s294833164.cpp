#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


vector<vector<Int>> G(10010);
vector<Int> c1(10010), c2(10010);
Int cnt = 0;

void dfs(int i, int j = -1) {
    c2[i] = c1[cnt];
    cnt++;
    for(int k = 0; k < G[i].size(); k++) {
        if(G[i][k] != j) {
            dfs(G[i][k],i);
        }
    }
    return;
}


int main() {
    Int N;
    cin >> N;
    rep(i,N-1) {
        Int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<Int> c(N);
    rep(i,N) cin >> c[i];
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());

    rep(i,N) c1[i] = c[i];

    dfs(0);

    Int sum = 0;
    rep1(i,N-1) sum += c1[i];

    cout << sum << endl;
    rep(i,N-1) cout << c2[i] << " ";
    cout << c2[N-1] << endl;
}