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
        cnt = vertex_num;
        for(int i = 0; i < vertex_num; ++i){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int get_root(int n)
    {
        if(parent[n] == n){
            return n;
        }else{
            return get_root(parent[n]);
        }
    }
    void unite(int a, int b)
    {
        int root_a=get_root(a),root_b=get_root(b);
        if(root_a == root_b) return;
        if(rank[root_a] < rank[root_b]){
            parent[root_a] = root_b;
            cnt--;
        }else if(rank[root_a] > rank[root_b]){
            parent[root_b] = root_a;
            cnt--;
        }else{
            parent[root_a] = root_b;
            ++rank[root_b];
            cnt--;
        }
    }
    int get_cnt()
    {
        return cnt;
    }
};

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>>a(m,vector<int>(2));
    for(int i = 0; i < m; ++i){
        cin >> a[i][0] >> a[i][1];
        a[i][0]--;
        a[i][1]--;
    }
    for(int i = 0; i < m; ++i){
        union_find uf(n);
        for(int j = (i % m), k = 0;k < m-1; j = ((j + 1) % m), k++){
            uf.unite(a[j][0], a[j][1]);//１組抜かしてそのcntを調べたい
        }
        if(uf.get_cnt() != 1) ans++;
    }
    cout << ans << endl;   
    return 0;
}