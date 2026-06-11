#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int cnt = 0;

void dfs(ll cur, int use){
    if(cur>N) return;
    if(use == 0b111) cnt++;

    dfs(cur*10+7, use|0b100);
    dfs(cur*10+5, use|0b010);
    dfs(cur*10+3, use|0b001);
}

int main(void){
    cin >> N;
    dfs(0,0b000);
    cout << cnt << endl;
}