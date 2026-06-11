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
long long N;
vll res;
priority_queue<ll> que;
void dfs(vector<vll> &G, vb &checked, ll u){
    checked[u] = true;
    res[u] = que.top(); que.pop();
    for(auto v: G[u]){
        if(!checked[v])
            dfs(G, checked, v);
    }
}

void solve(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c){
    vector<vll> G(N);
    REP(i, N-1){
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    REP(i, N){
        que.push(c[i]);
    }
    res.assign(N, 0);
    vb checked(N, false);
    dfs(G, checked, 0);
    ll cnt = 0;
    REP(i, N-1){
        cnt += min(res[a[i]], res[b[i]]);
    }
    cout << cnt << endl;
    REP(i, N){
        cout << res[i]<<" ";
    }
    cout << endl;


}

int main(){

    scanf("%lld",&N);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        a[i]--;
        b[i]--;
    }
    std::vector<long long> c(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&c[i]);
    }
    solve(N, std::move(a), std::move(b), std::move(c));
    return 0;
}
