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

void solve(long long N, long long K, std::vector<long long> A){
    ll M = 40;
    bool isFree = false;
    ll x = 0;
    for(ll j = 39; j >= 0; j--){
        //* calculate best bit
        ll num_one=0;
        REP(i, N){
            if(A[i]>>j & 1) num_one++;
        }
        bool bit = (num_one>(N-num_one))? false: true;
        if(isFree){
            if(bit) x = (x | (1LL<<j));
        }
        else{//* need to check K
            if((K>>j & 1) && (!bit) && !isFree) isFree = true;
            if((K>>j & 1) && (bit)) x = (x | (1LL<<j));
        }
    }
    ll ans = 0;
    REP(i, N) ans += x^A[i];
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}
