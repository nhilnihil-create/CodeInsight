#ifndef ENV_AC
    #define ENV_AC
    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    #include <fstream>
    #include <iostream>
    #include <sstream>
    #include <iomanip>
    #include <algorithm>
    #include <bitset>
    #include <array>
    #include <vector>
    #include <queue>
    #include <set>
    #include <cmath> // 変数名にy1が使えなくなるかも…。
    #include <map>
    #include <unordered_map>
    #include <unordered_set>
    #include <limits>
    #include <functional>
    #include <string>

    using int128_t = __int128_t;
    std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
        int64_t tmp; input >> tmp; value = tmp;
        return input;
    }
    std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
        output << (int64_t)value;
        return output;
    }

    namespace std {
        template<> class hash<int128_t>{
            public:
            size_t operator () ( const int128_t &x ) const {
                int64_t INF64 = std::numeric_limits<int64_t>::max();
                int64_t y1 = x / INF64;
                int64_t y2 = x % INF64;
                return hash<int64_t>()(y1) ^ hash<int64_t>()(y2);
            }
        };
    }

    int128_t imax(const int128_t a, const int128_t b) { return std::max(a, b); } // std::max, std::min は型が違うとエラーになるため、ラッパーを作る。
    int128_t imin(const int128_t a, const int128_t b) { return std::min(a, b); }
    int128_t iabs(const int128_t x) { return 0 <= x ? x : -x; }
    int128_t ipow(const int128_t x, const int128_t n) { int128_t ret = 1; for (int i = 0; i < n; i++) { ret *= x; } return ret; }

    #define rep(i, begin, end) for(int64_t i = ((int64_t)begin); i <= ((int64_t)end); i++) // (int64_t)end としておくと、end = v.size() - 2 みたいな入力で、v.size()が1でも正常(end = -1になる）に挙動する。
    #define rev(i, begin, end) for(int64_t i = ((int64_t)begin); ((int64_t)end) <= i; i--) // int128_tにすると、3重ループでコンパイルエラーになったのでint64_tにしておく。

    #define input1(begin, end, v1) v1.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i]; }
    #define input2(begin, end, v1, v2) v1.resize((end)+1); v2.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i]; } 
    #define input3(begin, end, v1, v2, v3) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i]; }
    #define input4(begin, end, v1, v2, v3, v4) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); v4.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i]; } 
    #define input5(begin, end, v1, v2, v3, v4, v5) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); v4.resize((end)+1); v5.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i] >> v5[i]; }  
    // input_arrayはbegin = 0のときのみ動作確認。Aの要素の型をテンプレートにして関数にしたほうが丁寧かもしれない。
    #define input_array(begin, N, M, A) A.resize((begin)+(N)); for (int i = 0; i < (begin)+(N); i++) { A[i].resize((begin)+(M)); } for (int i = begin; i < (begin)+(N); i++) { for (int j = begin; j < (begin)+(M); j++) { std::cin >> A[i][j]; }}

    std::vector<int> irange(const int begin, const int end) {
        std::vector<int> ret; for (int i = begin; i <= end; i++) { ret.push_back(i); }
        return ret;
    }

    template <typename T>
    std::vector<T> accumulate_vec(const std::vector<T>& vec, const bool reverse = false) {
        std::vector<T> ret; ret.resize(vec.size());
        if (reverse == false) {
            ret[0] = vec[0];
            for (int i = 1; i < ret.size(); i++) {
                ret[i] = ret[i-1] + vec[i];
            }
        } else {
            ret[ret.size()-1] = vec[ret.size()-1];
            for (int i = ret.size() - 2; 0 <= i; i--) {
                ret[i] = ret[i+1] + vec[i];
            }
        }
        return ret;
    }

    template <typename T>
    void printvec(const std::vector<T>& vec) {
        for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;
    }
#endif

// 木のクラス。
// 有向グラフと同様に表現する。
// （Tipsに含まれている関数で、こちらに移植していないものがあるので注意。get_children, calc_diameter）
class Tree_New {
    public:
    struct Edge { 
        int to; int64_t cost;
    };
    typedef std::vector<std::vector<Edge>> adj_list;
    adj_list G;
    int node_num;
    Tree_New() {}
    Tree_New(const int node_num_in) {
        node_num = node_num_in;
        G.resize(node_num);
    }
    void add_directed_edge(const int from, const int to, const long long cost) {
        Edge edge; edge.to = to; edge.cost = cost;
        G[from].push_back(edge);
    }
    void add_undirected_edge(const int node1, const int node2, const long long cost) {
        add_directed_edge(node1, node2, cost);
        add_directed_edge(node2, node1, cost);
    }
    // ret[i][t] := i->t の辺がG[i]の何番目にあるか。全方位木DPをやるときに使いやすい。
    std::vector<std::unordered_map<int, int>> edge_map() const {
        std::vector<std::unordered_map<int, int>> ret; ret.resize(G.size());
        for (int i = 0; i < G.size(); i++) {
            for (int j = 0; j < G[i].size(); j++) {
                ret[i][G[i][j].to] = j;
            }
        }
        return ret;
    }
    int128_t diameter() const {
        std::vector<std::unordered_map<int, int>> emp = edge_map();
        std::vector<std::vector<std::vector<int128_t>>> memo[3];
        for (int m = 0; m < 3; m++) {
            memo[m].resize(G.size());
            for (int i = 0; i < G.size(); i++) {
                memo[m][i].resize(G[i].size());
            }
        }
        std::function<std::vector<int128_t>(int, int, int)> dfs = [&] (int mode, int parent, int eid) {
            if (eid == -1 || eid == G[parent].size()) { return std::vector<int128_t>({0, 0}); }
            if (!memo[(mode + 3) % 3][parent][eid].empty()) { return memo[(mode + 3) % 3][parent][eid]; }
            if (mode != 0) {
                std::vector<int128_t> ret = dfs(mode, parent, eid + mode);
                ret.push_back(dfs(0, parent, eid)[0]);
                std::sort(ret.begin(), ret.end(), std::greater<int128_t>());
                ret.resize(2);
                return memo[(mode + 3) % 3][parent][eid] = ret;
            } else {
                int node = G[parent][eid].to;
                int r = emp[node][parent];
                return memo[(mode + 3) % 3][parent][eid] = std::vector<int128_t>({std::max(dfs(-1, node, r - 1)[0], dfs(1, node, r + 1)[0]) + G[parent][eid].cost});
            }
        };
        int128_t ret = 0;
        for (int i = 0; i < G.size(); i++) {
            std::vector<int128_t> tmp = dfs(1, i, 0);
            ret = std::max(ret, tmp[0] + tmp[1]);
        }
        return ret;
    }
};


//--code begin--

int128_t N;
std::vector<int128_t> a, b;
//std::string S;
//std::vector<std::string> ;
//double xa, ya, xb, yb, xc, yc;
//std::vector<double> ;

const int128_t MAX_N = 2e5 + 10;
//const int128_t MOD = 1e9 + 7;
//const int128_t INF = std::numeric_limits<int64_t>::max(); const int128_t NEG_INF = std::numeric_limits<int64_t>::min();
//using pair = std::pair<int64_t, int>;

Tree_New tree(MAX_N);

int main(int argc, char **argv) {
    std::cin.tie(0);
   	std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    
    std::cin >> N;
    input2(1, N - 1, a, b);

    rep (i, 1, N - 1) {
        tree.add_undirected_edge(a[i], b[i], 1);
    }

    //std::cout << "check" << std::endl;

    //std::cout << tree.diameter() << std::endl;

    if (tree.diameter() % 3 == 1) {
        std::cout << "Second" << std::endl;
    } else {
        std::cout << "First" << std::endl;
    }

    return 0;
}