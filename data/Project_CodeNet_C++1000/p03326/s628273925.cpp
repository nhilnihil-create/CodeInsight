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

void neg(vll a){
    REP(i, a.size()) a[i] = -a[i];
}

void solve(long long N, long long M, std::vector<long long> x, std::vector<long long> y, std::vector<long long> z){
    ll ans = 0;
    REP(S, 1LL<<3){
        vll tmp(N, 0);
        REP(i, N){
            if(S>>0 & 1) tmp[i] += -x[i];
            else tmp[i] += x[i];
            if(S>>1 & 1) tmp[i] += -y[i];
            else tmp[i] += y[i];
            if(S>>2 & 1) tmp[i] += -z[i];
            else tmp[i] += z[i];
        }
        sort(ALL(tmp)); reverse(ALL(tmp));
        ll tmpsum = 0;
        REP(i, M) tmpsum += tmp[i];
        ans = max(ans, tmpsum);
    }
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    std::vector<long long> z(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
        scanf("%lld",&z[i]);
    }
    solve(N, M, std::move(x), std::move(y), std::move(z));
    return 0;
}
