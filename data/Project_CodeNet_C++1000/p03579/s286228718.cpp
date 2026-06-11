#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long int;
int MAX_N = 1e5;
vector<int> is_odd(MAX_N, -1);
vector<vector<int>> edge(MAX_N, vector<int>{});
ll odd_num = 0;
ll even_num = 0;
ll n, m;

int dfs(int d, int v){
    if(is_odd[v] != -1){
        if(is_odd[v] == d % 2){return 0;}
        else{
            cout << n * (n-1) / 2 - m << endl;
            exit(0);
        }
    }
    is_odd[v] = d % 2; 
    if(d%2 == 0){even_num++;}
    else{odd_num++;}
    for(int i=0; i<edge[v].size(); i++){
        dfs(d+1, edge[v][i]);
    }
    return 0;
}

int main() {
    cin >> n >> m;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(0, 0);
    cout << odd_num * even_num - m << endl;
    return 0;
}