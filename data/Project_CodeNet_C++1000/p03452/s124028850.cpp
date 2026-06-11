#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

template <class T>
class UnionFindTree
{
private:
    const int n;
    vector<pair<int, T> > parent; // 親ノード
    vector<int> rank;             // 木の高さの上限

    pair<int, T> find(int x){
        if(parent[x].first == x){
            return parent[x];
        }else{
            pair<int, T> p = find(parent[x].first);
            p.second += parent[x].second;
            return parent[x] = p;
        }
    }
public:
    UnionFindTree(int n) : n(n){ // コンストラクタ
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = make_pair(i, 0);
        rank.assign(n, 0);
    }
    bool unite(int a, int b, T diff){ // aとbのグループを併合
        pair<int, T> x = find(a);
        pair<int, T> y = find(b);
        a = x.first;
        b = y.first;
        if(a != b){
            if(rank[a] < rank[b]){
                parent[a] = make_pair(b, y.second - x.second + diff);
            }else{
                parent[b] = make_pair(a, x.second - y.second - diff);
                if(rank[a] == rank[b])
                    ++ rank[a];
            }
            return true;
        }
        else{
            return x.second - y.second == diff;
        }
    }
    pair<bool, T> getDiff(int a, int b){ // aとbの値の差を調べる
        pair<int, T> x = find(a);
        pair<int, T> y = find(b);
        if(x.first == y.first)
            return make_pair(true, x.second - y.second);
        else
            return make_pair(false, 0);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    UnionFindTree<int> uft(n);
    for(int i=0; i<m; ++i){
        int l, r, d;
        cin >> l >> r >> d;
        -- l;
        -- r;
        if(!uft.unite(l, r, d)){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
