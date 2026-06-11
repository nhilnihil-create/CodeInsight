#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

struct edge {
    int to, cost;
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<edge>>g(N);
    rep(i, M){
        int l, r, d;
        cin >> l >> r >> d;
        l --;
        r --;
        edge e1 = {r, d};
        g[l].push_back(e1);
        edge e2 = {l, -d};
        g[r].push_back(e2);
    }
    vector<bool> visit(N);
    vector<int> cs(N);
    rep(i, N){
        if(! visit[i]){
            // 未探索の連結グラフを処理.
            queue<int> qs;
            qs.push(i);
            while(! qs.empty()){
                int p = qs.front();
                qs.pop();
                rep(j, g[p].size()){
                    edge e = g[p][j];
                    // 右向きが正.
                    if(! visit[e.to]){
                        cs[e.to] = e.cost + cs[p];
                        visit[e.to] = true;
                        qs.push(e.to);
                    }else if (cs[e.to] != e.cost + cs[p]){
                        cout << "No" << endl;
                        return 0;
                    }
                }

            }

        }
    }
    cout << "Yes" << endl;
    return 0;
}
