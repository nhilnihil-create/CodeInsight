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
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)

//* prime factorization in O(sqrt(n))
map<ll, ll> prime_factor(ll n){
    map<ll, ll> res;
    for(ll i=2; i*i <= n; i++){ //* n shrinks during the for-loop!
        while(n % i == 0){
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) {
        ++res[n];
    }
    return res;
}

void solve(long long N, long long P){
    auto pmap = prime_factor(P);
    ll ans = 1;
    for(auto x: pmap){
        ll degree = x.second/N;
        if(degree>0){
            rep(i, degree)
                ans *= x.first;
        }
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long P;
    scanf("%lld",&P);
    solve(N, P);
    return 0;
}
