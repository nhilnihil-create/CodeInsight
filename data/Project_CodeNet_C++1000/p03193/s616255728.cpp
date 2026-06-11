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


void solve(long long N, long long H, long long W, std::vector<long long> A, std::vector<long long> B){
    ll cnt = 0;
    rep(i, N){
        if(A[i]>= H && B[i]>= W)
            cnt ++;
    }
    cout << cnt << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, H, W, std::move(A), std::move(B));
    return 0;
}
