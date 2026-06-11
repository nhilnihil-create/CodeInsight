/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
vector<vector<int>> g;
vector<int> color;
vector<int> visited;

bool bi = true;

void dfs(int now, int c){
    color[now] = c;
    for(int i = 0; i < g[now].size(); i++){
        int next = g[now][i];
        if(color[next] != -1){
            if(color[next] == c){
                bi = false;
                return;
            }
        } else {
            if(visited[next]) continue;
            color[next] = !c;
            visited[next] = true;
            dfs(next, !c);
        }
    }
}

int main(void){
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n, -1);
    visited.resize(n, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);

    if(bi){
        ll w = 0;
        ll b = 0;
        for(int i = 0; i < n; i++){
            if(color[i] == 0){
                w++;
            } else {
                b++;
            }
        }

        cout << w * b - m << endl;
    } else {
        cout << n * (n - 1) / 2 - m << endl;
    }


}