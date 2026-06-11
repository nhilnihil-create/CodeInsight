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
#define REP(i,n) for(long long i(0);(i)<(n);(i)++)


void solve(long long N, std::vector<long long> A, std::vector<long long> B){
    vector<pll> rec(N);
    REP(i, N){
        rec[i].first = A[i]+B[i];
        rec[i].second = A[i];
    }
    sort(rec.begin(), rec.end());
    reverse(rec.begin(), rec.end());
    ll res = 0;
    REP(i, N){
        if(i % 2 == 0){ //* Takahashi
            res += rec[i].second;
        }
        else{ //* Aoki
            res -= (rec[i].first - rec[i].second);
        }
    }
    cout << res << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, std::move(A), std::move(B));
    return 0;
}
