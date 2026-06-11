#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <cstdio>

using namespace std;

int vis[50][100010];
int n;

void dfs(int rem, int dist){
    if(dist > 45) return;
    if(vis[dist][rem]) return;
    vis[dist][rem] = 1;
    for(int i = 0; i < 10; i++)
        dfs((rem*10+i)%n, dist+i);
}

int main(){

    cin >> n;
    for(int i = 1; i < 10; i++)
        dfs(i, i);

    for(int i = 1; i <= 45; i++)
        if(vis[i][0]){
            cout << i << endl;
            return 0;
        }
    return 0;
}	
