#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(m), y(m);
    vector<vector<int>> py(100010);
    for(int i = 0; i < m; i++){
        cin >> p.at(i) >> y.at(i);
        py.at(p.at(i)).push_back(y.at(i));
    }
    for(int i = 0; i < n; i++){
        sort(py.at(i+1).begin(), py.at(i+1).end());
    }
    for(int i = 0; i < m; i++){
        int v = p.at(i);
        printf("%06d", v);
        int id = lower_bound(py.at(p.at(i)).begin(), py.at(p.at(i)).end(), y.at(i)) - py.at(p.at(i)).begin();
        printf("%06d\n", id+1);
    }
}