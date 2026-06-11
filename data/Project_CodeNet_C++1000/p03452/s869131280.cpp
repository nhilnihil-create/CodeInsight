#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

vector <pair<int, long long> > edges[100000];
bool used[100000];
long long cost_from_start[100000];
long long dfs_max;
long long dfs_min;

bool dfs(int cur, long long cost){
    used[cur] = true;
    cost_from_start[cur] = cost;
    dfs_max = max(dfs_max, cost);
    dfs_min = min(dfs_min, cost);
    for(int i = 0; i < edges[cur].size(); i++){
        int next = edges[cur][i].first;
        long long d = edges[cur][i].second;
        if(used[next]){
            if(cost_from_start[next] != cost_from_start[cur] + d){
                return false;
            }
        } else {
            if(!dfs(next, cost + d)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int N;
    int M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int L;
        int R;
        long long D;
        cin >> L >> R >> D;
        edges[L - 1].push_back(make_pair(R - 1, D));
        edges[R - 1].push_back(make_pair(L - 1, - D));
    }

    for(int i = 0; i < N; i++){
        if(used[i]){
            continue;
        }
        dfs_max = LLONG_MIN;
        dfs_min = LLONG_MAX;
        if(!dfs(i, 0)){
            cout << "No" << endl;
            return 0;
        }
        if(dfs_max - dfs_min > 1000000000){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    
    cout << endl;
    return 0;
}
