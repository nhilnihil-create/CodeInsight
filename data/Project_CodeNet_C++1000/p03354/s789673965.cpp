#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int find_parent(int i, vector<int>& parent){
    if (i == parent[i]) return i;

    return parent[i] = find_parent(parent[i], parent);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adress(n);
    for (int i=0; i<n; i++){
        int p;
        cin >> p;
        adress[p-1] = i;
    }
    vector<int> parent(n);
    for (int i=0; i<n; i++) parent[i] = i;
    for (int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x = find_parent(x-1, parent); y = find_parent(y-1, parent);
        parent[max(x, y)] = parent[min(x, y)];
    }
    int ans=0;
    for (int i=0; i<n; i++){
        if (find_parent(i, parent) == find_parent(adress[i], parent)) ans += 1;
    }
    cout << ans << endl;
    return 0;
}