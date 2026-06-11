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

ll calDist(vll &fixD, vll &floatD){
    vll tmp = fixD;
    tmp.insert(tmp.end(), ALL(floatD));
    ll res = 24;
    for(auto x: tmp){
        res = min( res, min(x, 24-x));
    }
    for(ll i=0; i< tmp.size()-1; i++){
        for(ll j = i+1; j < tmp.size(); j++){
            ll dist = abs(tmp[i]-tmp[j]);
            dist = min(dist, 24 - dist);
            res = min(res, dist);
        }
    }
    return res;
}

void solve(long long N, std::vector<long long> D){
    map<ll, ll> recD;
    REP(i, N) recD[D[i]]++;
    vll D1, D2;
    for(auto x: recD){
        if(x.second > 2){
            cout<<0<<endl; return;
        }
        if(x.second == 1) D1.push_back(x.first);
        if(x.second == 2) D2.push_back(x.first);
    }
    vll fixD;
    for(auto x: D2){
        fixD.push_back(x); fixD.push_back(24-x);
    }
    ll len = D1.size();
    ll ans = 0;
    for(ll S = 0; S < (1LL << len); S++){
        vll floatD;
        REP(j, len){
            if(S>>j & 1) floatD.push_back(D1[j]);
            else floatD.push_back(24-D1[j]);
        }
        ans = max(ans, calDist(fixD, floatD));
    }
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> D(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&D[i]);
    }
    solve(N, std::move(D));
    return 0;
}
