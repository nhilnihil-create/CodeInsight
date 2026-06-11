#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 101;

int par[MAX_N];
int rank_[MAX_N];

void init(int n){
    for(int i = 1; i <= n; i++){
        par[i] = i;
        rank_[i] = 0;
    }
}

int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank_[x] < rank_[y]) par[x] = y;
    else{
        par[y] = x;
        if(rank_[x] == rank_[y]) rank_[x]++;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    init(n);
    if(n%2 == 0){
        for(int i = 1; i <= n/2; i++){
            unite(i, n-i+1);
        }
    }
    else{
        for(int i = 1; i <= (n-1)/2; i++){
            unite(i, n-i);
        }
    }
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(!same(i, j)){
                ans.emplace_back(i, j);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}