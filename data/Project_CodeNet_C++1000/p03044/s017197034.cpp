#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int n;
vector<vector<pair<int,long long>>> x(100005);
bool color[100005] = {0};
bool checked[100005] = {0};



void dfs(int k)
{
    if (checked[k] == 1){
        return;
    }
    
    checked[k] = 1;
    
    for (auto& i : x[k]){
        if (i.second%2 == 0){
            color[i.first] = color[k];
        }
        else {
            color[i.first] = !color[k];
        }
        dfs(i.first);
    }
}

int main()
{
    cin >> n;
    long long w;
    int u,v;
    
    x.resize(n);
    for (int i = 0;i < n-1;i++){
        cin >> u >> v >> w;
        u--;
        v--;
        x[u].push_back(make_pair(v,w));
        x[v].push_back(make_pair(u,w));
    }

    color[0] = 0;
    dfs(0);
    
    for (int i = 0;i < n;i++){
        cout << color[i] << endl;
    }
}
