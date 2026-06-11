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
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define elnd endl //* missspell check
const ll INF = 1LL << 60;

void add_edge(vector<vll> &G, ll u, ll v){
    G[u].push_back(v); G[v].push_back(u);
}

bool dfs(vector<vll> &G, vb &checked, vll &match, ll v){
    //* match is initialized -1 outside
    checked[v] = true;
    REP(i, G[v].size()){
        ll u = G[v][i], w = match[u];
        if(w < 0 || !checked[w] && dfs(G, checked, match, w)){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

ll BipartiteMatching(vector<vll> &G){
    ll N = G.size();
    vb checked(N, false);
    vll match(N, -1);
    ll res = 0;
    REP(v, N){
        if(match[v] < 0){
            fill(ALL(checked), false);
            if(dfs(G, checked, match, v)){
                res++;
            }
        }
    }
    return res;
}
void solve(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d){
    vector<vll> G(2*N);
    REP(i, N){
        REP(j, N){
            if(a[i] < c[j] && b[i] < d[j]){
                add_edge(G, i, j+N);
            }
        }
    }
    ll m = 0;
    m = BipartiteMatching(G);
    cout<<m<<endl;
}

void solve_old(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d){
    map<pll, bool> points;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        points[pll(a[i], b[i])] = true;
        points[pll(c[i], d[i])] = false;
    }
    map<pll, bool>::iterator it, it_inner;
    while(true){
        bool pairFound = false;
        for(it = points.begin(); it != points.end(); it++){
            if(it->second){ //* red point
                for(it_inner = points.begin(); it_inner != it; it_inner ++){
                    if(it_inner->second == false && it->first < it_inner->first){
                        pairFound = true;
                        break;
                    }
                }

            } 
            if(pairFound) break;
        }
        if(pairFound){
            cnt ++;
            points.erase(it);
            points.erase(it_inner);
        }
        else{
            break;
        }
    }
    cout << cnt << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    std::vector<long long> c(N);
    std::vector<long long> d(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&c[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, std::move(a), std::move(b), std::move(c), std::move(d));
    return 0;
}
