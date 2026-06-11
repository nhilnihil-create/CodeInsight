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


void solve(long long N, long long K, std::vector<long long> a){
    vll s(N+1, 0);
    REP(i, N){
        s[i+1] = s[i]+a[i];
    }
    vll R;
    REP(i, N){
        for(ll j = i+1; j <= N; j++){
            R.emplace_back(s[j]-s[i]);
        }
    }
    vll rec;
    for(ll digit=63; digit >=0; digit --){
        ll tmp = 0;
        sort(ALL(R)); reverse(ALL(R));
        REP(i, R.size()){
            if(R[i] >> digit & 1){
                tmp++;
            }
        }
        if(tmp < K){
            REP(i, R.size()){
                R[i] = R[i] & ~(1LL<<digit);
            }
        }
        else{
            R.resize(tmp);
            rec.push_back(digit);
        }
    }
    ll res = 0;
    for(auto x: rec){
        res += 1LL<<x;
    }
    cout<<res<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, K, std::move(a));
    return 0;
}
