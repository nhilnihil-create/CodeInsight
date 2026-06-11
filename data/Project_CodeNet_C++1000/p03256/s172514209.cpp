#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M){
        string s; cin >> s;
        vector<vector<int>> g(N);
        vector<vector<int>> degree(N, vector<int>(2, 0));
        for(int i=0;i<M;i++){
            int a, b; cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
            ++degree[a][s[b]-'A'];
            ++degree[b][s[a]-'A'];
        }
        int rest = N;
        vector<int> valid(N, 1);
        queue<int> qu;
        for(int i=0;i<N;i++){
            if(!degree[i][0] || !degree[i][1]){
                qu.push(i);
                valid[i] = 0;
                --rest;
            }
        }
        while(!qu.empty()){
            int p = qu.front(); qu.pop();
            for(auto next : g[p]){
                if(!valid[next]) continue;
                --degree[next][s[p]-'A'];
                if(!degree[next][s[p]-'A']){
                    qu.push(next);
                    valid[next] = 0;
                    --rest;
                }
            }
        }
        cout << (rest ? "Yes" : "No") << endl;
    }
}