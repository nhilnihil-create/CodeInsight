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


void solve(long long N, std::vector<long long> A){
    vll orig(N, 0);
    REP(i, N){
        orig[i] = i - A[i];
    }
    REP(i, N){
        if(orig[i]<0 || orig[i] > i){
            cout<<-1<<endl; return;
        }
        if(i > 0){
            if(orig[i] < orig[i-1]){
                cout<<-1<<endl; return;
            }
        }
    }

    ll res = 0;
    for(ll i=N-1; i >=0 ; i--){
        if(i == N-1) res += i - orig[i];
        else if(orig[i] - orig[i+1]){
            res += i - orig[i];
        }
    }
    cout<<res<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
