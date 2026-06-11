#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

class UnionFind{
    public:
        UnionFind(int N) : parent(N), rank(N){
            for(int i = 0; i < N; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int find(int n){
            if(parent[n] == n){
                return n;
            }
            return parent[n] = find(parent[n]);
        }

        void merge(int m, int n){
            int root_x = find(m);
            int root_y = find(n);
            if(root_x == root_y){
                return;
            }
            if(rank[root_x] < rank[root_y]){
                parent[root_x] = root_y;
            }else if(rank[root_x] > rank[root_y]){
                parent[root_y] = root_x;
            }else{
                parent[root_y] = root_x;
                rank[root_x]++;
            }
        }

        bool equivalent(int x, int y){
            return find(x) == find(y);
        }

    private:
        vector<int> parent;
        vector<int> rank;

};

ll g[100010];

signed main(){
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    ll X, Y, Z;
    REP(i, M){
        cin >> X >> Y >> Z;
        X--; Y--;
        uf.merge(X, Y);
    }
    REP(i, N) g[uf.find(i)] = 1;
    PRINT(accumulate(g, g + N, 0LL));
    return 0;
}