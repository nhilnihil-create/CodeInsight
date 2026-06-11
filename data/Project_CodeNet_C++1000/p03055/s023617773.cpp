#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <time.h>

//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define SORTR(x) sort(x.begin(),x.end(),greater<int>())
#define rn return
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
using ll = long long;
typedef std::pair<int,int> pii;
typedef std::pair<int,double> pid;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;

#define PI 3.14159265358979323846264338327950L
const int mod = 1000000007;


int D;
int N;

void dfs(int node, int parent, vector<vector<int>>& g, int cnt){
    if (cnt > D){
        N = node;
        D = cnt;
    }
    for(auto ne: g[node]){
        if (ne == parent) continue;
        dfs(ne,node,g,cnt+1);
        
    }    
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n+1,vector<int>());
    rep(i,n-1){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    D = 0;
    N = -1;
    dfs(1,-1,g,0);
    
    dfs(N,-1,g,0);
    
    if (D == 0) cout << "First";
    else if (D%3 == 1) cout << "Second";
    else cout << "First";
    
    
}





int main(){
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
        cout << endl;
    }
}



































