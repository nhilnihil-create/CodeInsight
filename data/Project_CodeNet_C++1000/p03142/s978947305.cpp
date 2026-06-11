#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
using qll = queue<ll>;
using vb = vector<bool>;
using sll = stack<ll>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)
#define REP(i,n) for(long long i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define elnd endl //* missspell check
ll INF = 1LL << 60;


void dfs2(vector<vll> &G, vb &checked, vll &ts, ll u){
    checked[u] = true;
    for(auto v: G[u]){
        if(!checked[v])
            dfs2(G, checked, ts, v);
    }
    ts.push_back(u);
}

vll dfs_toposort(vector<vll> &G, vb &checked){
    ll N = G.size();
    fill(ALL(checked), false);
    vll ts;
    REP(i, N){
        if(!checked[i]){
            dfs2(G, checked, ts, i);
        }
    }
    reverse(ALL(ts));
    return ts;
}

void solve(long long N, long long M, std::vector<long long> A, std::vector<long long> B){
    vector<vll> G(N), Ginv(N);
    M += N-1;
    REP(i, M){
        G[A[i]].push_back(B[i]);
        Ginv[B[i]].push_back(A[i]);
    }
    //* topological sort
    vb checked(N, false);
    vll ts = dfs_toposort(G, checked);
    //* 
    vll tsinv(N);
    REP(i, N){
        //* vectex ts[i] --> position i
        tsinv[ts[i]] = i;
    }
    //* find parent
    REP(v, N){
        if(Ginv[v].empty())
            cout << 0 << endl;
        else{
            ll res = -1;
            for(auto x: Ginv[v]){
                res = max(res, tsinv[x]);
            }
            cout << ts[res]+1 << endl;
        }
    }

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(N-1+M);
    std::vector<long long> B(N-1+M);
    for(int i = 0 ; i < N-1+M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        A[i]--; B[i]--;
    }
    solve(N, M, std::move(A), std::move(B));
    return 0;
}
