#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;
using P = pair<ll,ll>;

int main(){
    ll H, W; cin >> H >> W;
    vvll dist(H, vll(W, -1));
    vector<vector<char>> grid(H, vector<char>(W));
    queue<P> q;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '#'){
                q.push(P(i, j));
                dist[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        P x = q.front();
        q.pop();
        ll h = x.first, w = x.second;
        if(0 <= h-1){
            if(grid[h-1][w] == '.'){
                dist[h-1][w] = dist[h][w] + 1;
                grid[h-1][w] = '#';
                q.push(P(h-1, w));
            }
        }
        if(h+1 < H){
            if(grid[h+1][w] == '.'){
                dist[h+1][w] = dist[h][w] + 1;
                grid[h+1][w] = '#';
                q.push(P(h+1, w));
            }
        }
        if(0 <= w-1){
            if(grid[h][w-1] == '.'){
                dist[h][w-1] = dist[h][w] + 1;
                grid[h][w-1] = '#';
                q.push(P(h, w-1));
            }
        }
        if(w+1 < W){
            if(grid[h][w+1] == '.'){
                dist[h][w+1] = dist[h][w] + 1;
                grid[h][w+1] = '#';
                q.push(P(h, w+1));
            }
        }
    }
    ll n = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            n = max(n,dist[i][j]);
        }
    }
    cout << n;
}