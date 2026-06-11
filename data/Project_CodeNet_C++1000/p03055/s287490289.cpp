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

using namespace std;
vector <int> edges[200000];
int diameter;
bool used[200000];
int dfs(int cur_node){
    used[cur_node] = true;
    vector <int> dists;
    for(int i = 0; i < edges[cur_node].size(); i++){
       int next_node = edges[cur_node][i];
       if(!used[next_node]){
        dists.push_back(1 + dfs(next_node));
       } 
    }

    sort(dists.begin(), dists.end());
    if(dists.size() >= 2){
        diameter = max(diameter, dists[dists.size() - 1] + dists[dists.size() - 2]);
    }

    if(dists.size() == 0){
        return 0;
    }  
    return *max_element(dists.begin(), dists.end());
}

bool win_dp[200001];
int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N - 1; i++){
        int a;
        int b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    diameter = max(diameter, dfs(0));

    win_dp[0] = true;
    win_dp[1] = false;
    for(int i = 2; i <= diameter; i++){
        if(!win_dp[i - 2] || !win_dp[i - 1]){
            win_dp[i] = true;
        } else {
            win_dp[i] = false;
        }
    }
    if(win_dp[diameter]){
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}
