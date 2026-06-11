#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<class T> void chmax(T& x, T y) {if(x < y) x = y;} 
int N;
int tp;
bool used[200010];
vector<int> G[200010];

int dfs(int n, int& di){
    used[n] = true;

    vector<int> res = {0, 0};
    for(auto& u : G[n]){
        if(!used[u]){
            res.push_back(dfs(u, di));
        }
    }
    sort(res.rbegin(), res.rend());
    chmax(di, res[0] + res[1] + 1);
    return res[0] + 1;
}

int main(){
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int di = 0;
    dfs(1, di);
    cout << (di % 3 != 2 ? "First" : "Second")  << endl;
    return 0;
}