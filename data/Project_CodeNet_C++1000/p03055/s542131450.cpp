#include <bits/stdc++.h>
#define reps(i,a,b) for(long long int i=a;i<b;i++)
#define rep(i,a) for(long long int i=0;i<a;i++)
typedef long long int ll;
using namespace std;
//http://kyopro.hateblo.jp/entry/2019/05/06/043431

class Tree {
public:
    int n;
    vector<vector<pair<int, int>>> adj;

    Tree(int nn) { n = nn;
    adj.resize(n);
    }

    void add_edge(const int v1, const int v2, const int w) {
        adj[v1].push_back(make_pair(v2, w));//v1→v2 重みがw
        adj[v2].push_back(make_pair(v1, w));//adj[v1]にはv1から行けるところが入ってる。これは無向グラフの奴
    }

    pair<int, int> Dfs(const int prev, const int cur) { //深さ優先探索　previous昔　current　今
        pair<int, int> res(cur, 0); //result。右側が距離？
        for (const auto &e : adj[cur]) {//adj[cur]というベクトルの初めから最後までやります　参照auto& eを書くと、コンテナ内の要素を変更できる。＆がないと変更できない//次に行ける場所へと！
            if (prev == e.first) continue;//後戻りはしない
            auto nxt = Dfs(cur, e.first);//そこから先の距離を返せ//再帰のキモ
            nxt.second += e.second;//そこから先の距離＋今回の移動分
            if (res.second < nxt.second) res = nxt;//最大値を求める
        }
        return res;
    }




    

    pair<int, int> farthest_pair;
    int Diameter() {
        const auto v1 = Dfs(-1, 0), v2 = Dfs(-1, v1.first);//初期状態で初めの場所とかないから-1
        farthest_pair = make_pair(v1.first, v2.first);
        return v2.second;
    }
};

bool Solve() {
    int n;
    cin >> n;

    Tree tree(n);
    for (int i = 0, a, b; i + 1 < n; ++i) {
        cin >> a >> b;
        tree.add_edge(a - 1, b - 1, 1);
    }

    return tree.Diameter() % 3 != 1;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << setprecision(8) << setiosflags(ios::fixed);

    if (Solve()) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}