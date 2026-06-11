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

void solve(long long N, long long M, std::vector<long long> A){
    vll S(N+1, 0);
    REP(i, N) S[i+1] = (S[i] + A[i]) % M;
    ll total = (S[N] - S[0]) % M;
    map<ll, vll> R;
    REP(r, N){
        ll x = S[N]-S[r+1];
        if(x < 0 ) x+= M;
        if(R.count(x)){
            R[x].push_back(r+1);
        }
        else{
            R[x] = vll(1, r+1);
        }
    }
    ll cnt = 0;
    REP(l, N){
        ll tmp = (total - S[l]) % M;
        if(tmp < 0) tmp += M;
        if(!R.count(tmp)) continue;
        cnt += R[tmp].end() - upper_bound(ALL(R[tmp]), l);
    }
    cout<<cnt<<endl;



}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, M, std::move(A));
    return 0;
}
