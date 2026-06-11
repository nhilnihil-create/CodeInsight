#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n,m;
    cin >> n >> m;
    string str;
    cin >> str;

    vector<vector<LL>> vertex(n+1);

    for(int i = 0; i < m; i++){
        LL a,b;
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    vector<bool> ng(n+1,false);
    vector<LL> state(n+1,0);

    queue<LL> que;
    for(int i = 1; i <= n; i++){
        if(!ng[i]){
            que.push(i);
            state[i] = 1;
        }
        while(!que.empty()){
            LL t = que.front();
            que.pop();
            if(ng[t] || state[t] == 2)continue;
            state[t] = 2;
            vector<bool> check(2,false);
            vector<LL> back;
            for(int j = 0; j < vertex[t].size(); j++){
                if(!ng[vertex[t][j]]){
                    check[str[vertex[t][j] - 1] - 'A'] = true;
                    if(state[vertex[t][j] == 0]){
                        que.push(vertex[t][j]);
                        state[vertex[t][j]] = 1;
                    }else if(state[vertex[t][j]] == 2){
                        back.push_back(vertex[t][j]);
                    }
                }
            }
            if(check[0]&&check[1]){

            }else{
                ng[t] = true;
                for(int j = 0; j < back.size(); j++){
                    que.push(back[j]);
                    state[back[j]] = 1;
                }
            }
        }
    }

    bool ok = false;
    for(int i = 1; i < n+1; i++){
        ok |= (!ng[i]);
    }

    if(ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}