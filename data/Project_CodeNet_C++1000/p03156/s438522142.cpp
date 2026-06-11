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


void solve(long long N, long long A, long long B, std::vector<long long> P){
    ll cntA=0, cntB=0, cntC=0;
    A++; B++;
    REP(i, N){
        if(P[i]<A){
            cntA++;
        }
        else if(P[i]<B){
            cntB++;
        }
        else{
            cntC++;
        }
    }
    cout << min(cntA, min(cntB, cntC)) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&P[i]);
    }
    solve(N, A, B, std::move(P));
    return 0;
}
