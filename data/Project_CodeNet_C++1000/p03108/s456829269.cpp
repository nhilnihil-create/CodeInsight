#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

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
        ll size[MAX_N];
        int groups_;
    
    public:
        void init(ll n){ // initializes the tree 
            for(ll i=0; i<n; i++){
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
        ll sizeOf(int x){
            return size[rootOf(x)];
        }
};

int main(void){
    ll n, m;
    cin >> n >> m;
    vector<P> ab;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        ab.push_back(P(a, b));
    }

    UnionFind tree;
    tree.init(n);

    stack<ll> anss;
    ll ans = n * (n - 1) / 2;
    anss.push(ans);

    for(int i = m-1; i >= 0; i--){
        int a = ab[i].first;
        int b = ab[i].second;
        if(!tree.isSameGroupe(a, b)){
            ans -= (tree.sizeOf(a) * tree.sizeOf(b));
            anss.push(ans);
            tree.unite(a, b);
        }
        else{
            anss.push(ans);
        }
    }

    anss.pop();
    for(int i = 1; i <= m; i++){
        cout << anss.top() << endl;
        anss.pop();
    }
    return 0;
}