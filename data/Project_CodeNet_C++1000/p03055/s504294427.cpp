#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

class Tree{
public:
    int N;
    vector<vector<int>> G;

    Tree(int n){
        N = n;
        G.resize(N);
    }

    void make_edge(int s, int t){
        G[s].push_back(t);
        G[t].push_back(s);
    }

    P find_farthest(int n, int par){
        P ret = P(1, n);
        for(int i = 0; i < (int)G[n].size(); i++){
            if(G[n][i] != par){
                P tmp = find_farthest(G[n][i], n);
                tmp.first++;
                ret = max(ret, tmp);
            }
        }

        return ret;
    }

    int dfs(int n, int par){
        int mx = 0;
        for(int i = 0; i < (int)G[n].size(); i++){
            int nx = G[n][i];
            if(nx != par){
                mx = max(mx, dfs(nx, n) + 1);
            }
        }

        return mx;
    }

    int tyokkei(){
        P p = find_farthest(0, -1);
        //cout << "leaf = " << n << endl;
        return dfs(p.second, -1);
    }
};

int main(){
    int N;
    cin >> N;

    if(N == 1){
        cout << "First" << endl;
        return 0;
    }

    Tree tr = Tree(N);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tr.make_edge(a, b);
    }

    int x = tr.tyokkei();
    //cout << "x = " << x << endl;

    if(x % 3 != 1){
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
