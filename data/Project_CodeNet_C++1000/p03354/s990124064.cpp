#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

# define MAX_N 1000010 // 10^6 + 10

// UnionFindTree
// 使い方(インスタンス名 : tree)
// インスタンス生成 : UnionFind tree;
// tree.init(要素数)
// uniteしたりsameかどうか判定したり

class UnionFind{
    private:
        int par_[MAX_N];
        int rank_[MAX_N];
        int size[MAX_N];
        int groups_;
    
    public:
        void init(int n){ // initializes the tree 
            for(int i=0; i<n; i++){
                par_[i] = i;
                rank_[i] = 0;
                size[i] = 1;
            }
            groups_ = n;
        } 
        int rootOf(int x){ // returns the root of x 
            if(par_[x] == x){
                return x;
            }
            else{
                return par_[x] = rootOf(par_[x]);
            }
        } 
        void unite(int x, int y){ // unites x and y 
            x = rootOf(x);
            y = rootOf(y);
            if(x == y) return;
            if(rank_[x] < rank_[y]){
                par_[x] = y;
                groups_--;
                size[y] += size[x];
            }
            else{
                par_[y] = x;
                groups_--;
                size[x] += size[y];
                if(rank_[x] == rank_[y]) rank_[x]++;
            }
        }
        bool isSameGroupe(int x, int y){ // whether x and y are united
            return rootOf(x) == rootOf(y);
        }
        int countGroups(){ // returns the number of groups
            return groups_;
        }
        // 6 / 19 Updated!! (連結成分のサイズを返す)
        int sizeOf(int x){
            return size[rootOf(x)];
        }
};

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }

    UnionFind tree;
    tree.init(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        tree.unite(x, y);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(tree.isSameGroupe(i, p[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}