#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 200001;

int n;
vector <int> v[N];

pair <int, int> dfs(int node, int pnode, int dep){
    auto ret = make_pair(dep, node);
    for(auto &i : v[node]){
        if(i == pnode) continue;
        ret = max(ret, dfs(i, node, dep + 1));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int d = dfs(dfs(1, 0, 1).second, 0, 1).first;
    if((d - 2) % 3) cout << "First\n";
    else cout << "Second\n";
}
