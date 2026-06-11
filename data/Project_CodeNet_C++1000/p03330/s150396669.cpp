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
#define enld endl //* missspell check
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

void solve(long long N, long long C, std::vector<std::vector<long long>> D, std::vector<std::vector<long long>> c){
    vector<vll> diag(2*N-1, vll(C, 0));
    REP(r, 2*N-1){ //* diagonal r
        for(ll i = 0; i <= r; i++){
            ll j = r-i;
            if(0 > i || i >= N || 0 > j || j >= N) continue;
            ll color = c[i][j];
            REP(k, C){
                //* color --> k
                diag[r][k] += D[color][k];
            }
        }
    }
    ll ans = INF;
    REP(i, C){
        REP(j, C){
            if(i == j) continue;
            REP(k, C){
                if(k == i || k == j) continue;
                ll tmp = 0;
                REP(r, 2*N-1){
                    if(r % 3 == 0) tmp += diag[r][i];
                    if(r % 3 == 1) tmp += diag[r][j];
                    if(r % 3 == 2) tmp += diag[r][k];
                }
                chmin(ans, tmp);
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long C;
    scanf("%lld",&C);
    std::vector<std::vector<long long>> D(C, std::vector<long long>(C));
    for(int i = 0 ; i < C ; i++){
        for(int j = 0 ; j < C ; j++){
            scanf("%lld",&D[i][j]);
        }
    }
    std::vector<std::vector<long long>> c(N, std::vector<long long>(N));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%lld",&c[i][j]);
            c[i][j] --;
        }
    }
    solve(N, C, std::move(D), std::move(c));
    return 0;
}
