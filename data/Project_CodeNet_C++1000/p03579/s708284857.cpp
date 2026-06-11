#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> G;
vector<int> num;
void dfs(int s){
    for(int e: G[s]){
        if(num[e] == 0) {
            num[e] = -num[s];
            dfs(e);
        }
    }
}
int main(){
    long long N, M;
    cin >> N >> M;
    G.resize(N);
    vector<int> a(M), b(M);
    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    num.resize(N, 0);
    num[0] = 1;
    dfs(0);
    long long cnt = 0;
    for(int i = 0; i < N; i++){
        if(num[i] == 1) cnt++;
    }
    long long cnteq = 0;
    int flag = 0;
    for(int i = 0; i < M; i++){
        if(num[a[i]] != num[b[i]]) cnteq++;
        else flag = 1;
    }
    if(flag == 0) cout << cnt * (N - cnt) - cnteq << endl;
    else cout << N * (N - 1) / 2 - M << endl;
}