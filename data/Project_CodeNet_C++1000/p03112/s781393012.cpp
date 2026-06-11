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

void solve(long long A, long long B, long long Q, std::vector<long long> s, std::vector<long long> t, std::vector<long long> x){
    REP(q, Q){
        ll xnow = x[q];
        vll tmp_s, tmp_t;
        auto it = lower_bound(ALL(s), xnow);
        if(it != s.end()){
            tmp_s.push_back(*it);
        }
        it = upper_bound(ALL(s), xnow);
        if(it != s.begin()){
            tmp_s.push_back(*(--it));
        }
        it = lower_bound(ALL(t), xnow);
        if(it != t.end()){
            tmp_t.push_back(*it);
        }
        it = upper_bound(ALL(t), xnow);
        if(it != t.begin()){
            tmp_t.push_back(*(--it));
        }

        ll ans = INF;
        for(auto ts: tmp_s){
            for(auto tt: tmp_t){
                ans = min(ans, abs(xnow-ts)+abs(ts-tt));
                ans = min(ans, abs(xnow-tt)+abs(ts-tt));
            }
        }
        cout<<ans<<endl;
    }
    
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> s(A);
    for(int i = 0 ; i < A ; i++){
        scanf("%lld",&s[i]);
    }
    std::vector<long long> t(B);
    for(int i = 0 ; i < B ; i++){
        scanf("%lld",&t[i]);
    }
    std::vector<long long> x(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&x[i]);
    }
    solve(A, B, Q, std::move(s), std::move(t), std::move(x));
    return 0;
}
