/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;

int n;
int m;
int valid;
int mem[N];
int cost[10];

int go(int lft){
    if(lft == 0)
        return 0;
    if(~mem[lft])
        return mem[lft];
    int bst = -1e2;
    for(int i = 1; i <= 9; i++){
        if(valid & (1 << i) && lft >= cost[i]){
            int ret = go(lft - cost[i]);
            if(ret != -1e2)
                bst = max(bst , ret + 1);
        }
    }
    return mem[lft] = bst;
}

vector < int > mine;

void build(int lft){
    for(int i = 9; i >= 1; i--){
        if(valid & (1 << i) && lft >= cost[i] && go(lft) >= 0 && go(lft - cost[i]) >= 0 && go(lft) == go(lft - cost[i]) + 1){
            mine.push_back(i);
            build(lft - cost[i]);
            break;
        }
    }
}

int main(){
    memset(mem , -1 , sizeof mem);
    cost[1] = 2;
    cost[2] = 5;
    cost[3] = 5;
    cost[4] = 4;
    cost[5] = 5;
    cost[6] = 6;
    cost[7] = 3;
    cost[8] = 7;
    cost[9] = 6;
    scanf("%d%d" , &n , &m);
    for(int i = 1; i <= m; i++){
        int x;
        scanf("%d" , &x);
        valid |= 1 << x;
    }
    int sz = go(n);
    build(n);
    sort(mine.rbegin() , mine.rend());
    for(auto v : mine)
        printf("%d" , v);
}