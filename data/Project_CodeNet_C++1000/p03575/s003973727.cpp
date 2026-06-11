#include<iostream>
#include<vector>
using namespace std;
class union_find{
private:
    vector<int>parent;
    vector<int>rank;
    int cnt;
public:
    union_find(int vertex_num)
    {
        parent.resize(vertex_num);
        rank.resize(vertex_num);
        for(int i = 0; i < vertex_num; ++i){
            parent[i] = i;
            rank[i] = 0;
        }
        cnt = vertex_num;
    }
    int get_root(int n)
    {
        if(parent[n] == n){
            return n;
        }else{
            return get_root(parent[n]);
        }
    }
    bool is_same(int a, int b)
    {
        return get_root(a) == get_root(b);
    }
    void unite(int a, int b)
    {
        int root_a=get_root(a),root_b=get_root(b);
        if(root_a == root_b)return;
        if(rank[root_a] < rank[root_b]){
            parent[root_a] = root_b;
            --cnt;
        }else if(rank[root_a] > rank[root_b]){
            parent[root_b] = root_a;
            --cnt;
        }else{
            parent[root_a] = root_b;
            ++rank[root_b];
            --cnt;
        }
    }
    bool is_all_connected()
    {
        return cnt == 1;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>ab(m);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ab[i] = make_pair(a, b);
    }

    int ans = 0;
    for(int i = 0; i < m; ++i){
        union_find uf(n);
        for(int j = 0; j < m; ++j){
            if(i == j)continue;
            uf.unite(ab[j].first, ab[j].second);
        }
        if(!uf.is_all_connected()){
            ++ans;
        }
    }
    cout << ans << endl;
}
