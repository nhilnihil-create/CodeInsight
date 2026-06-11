#include <bits/stdc++.h>
using namespace std;
int N,M;
int res = 0;
set<int>Set;
void dfs(int now,vector<bool> &ok,vector<vector<int>> &vec) {
    for(int i = 0; i < vec[now].size(); i++) {
        if(ok[vec[now][i]] == false) {
            ok[vec[now][i]] = true;
            Set.insert(vec[now][i]);
            dfs(vec[now][i],ok,vec);
        }
    }
}
int main(){
    cin >> N >> M;
    vector<int>a(M);
    vector<int>b(M);
    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    for(int i = 0; i < M; i++) {
        vector<vector<int>>vec(N,vector<int>(0,{}));
        for(int j = 0; j < M; j++) {
            if(i == j) {
                continue;
            }
            vec[a[j]].push_back(b[j]);
            vec[b[j]].push_back(a[j]);
        }
        vector<bool>ok(N,false);
        ok[0] = true;
        Set.clear();
        dfs(0,ok,vec);
        Set.insert(0);
        if(Set.size() == N) {
            res++;
        }
    }
    cout << M-res << endl;
}