#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct UnionFind
{
    vector<int> par;

    UnionFind(int n): par(n){
        for(int i = 0;i < n;++i){
            par.at(i) = i;
        }
    }

    int root(int x){
        if(par.at(x) == x){
            return x;
        }else{
            return par.at(x) = root(par.at(x));
        }
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return;
        }else{
            par.at(rx) = ry;
        }
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int n,m,i;
    cin >> n >> m;

    vector<int> p(n);

    for(i = 0;i < n;++i){
        cin >> p.at(i);
    }

    UnionFind tree(n);

    for(i = 0;i < m;++i){
        int x,y;
        cin >> x >> y;
        tree.unite(x-1,y-1);
    }

    int ans = 0;
    for(i = 0;i < n;++i){
        if(tree.same(i,p.at(i)-1)){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}