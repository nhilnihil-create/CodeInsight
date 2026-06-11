#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>

using namespace std;

bool check[100000];
long long pos[100000];

pair<long long, long long> dfs(int node, vector<vector<pair<int, int>>> &E){
    check[node] = true;

    pair<long long, long long> ret = make_pair(0, 0);

    for(auto next : E[node]){
        int nextNode = next.first;
        int nextCost = pos[node] + next.second;

        if(!check[nextNode]){
            pos[nextNode] = nextCost;
            auto temp = dfs(nextNode, E);
            ret.first = min(ret.first, temp.first);
            ret.second = max(ret.second, temp.second);
        }
        else{
            if(pos[nextNode] != nextCost){
                return make_pair(-1e9 - 1, 1e9 + 1);
            }
        }
    }

    return ret;
}

int main(){

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> E(N);

    int L, R, D;
    for(int i  = 0; i < M; i++){
        cin >> L >> R >> D;

        E[L - 1].push_back(make_pair(R - 1, D));
        E[R - 1].push_back(make_pair(L - 1, -D));
    }

    for(int i = 0; i < N; i++){
        check[i] = false;
    }
    memset(pos, -1, sizeof(pos));

    bool isOk = true;
    for(int i = 0; i < N; i++){
        if(!check[i]){
            pos[i] = 0;
            pair<long long, long long> minMax = dfs(i, E);
            if(minMax.second - minMax.first > 1e9){
                isOk = false;
                break;
            }
        }
    }

    if(isOk){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}