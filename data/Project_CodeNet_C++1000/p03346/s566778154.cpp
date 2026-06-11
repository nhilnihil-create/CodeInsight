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


void solve(long long N, std::vector<long long> P){
    if(N==1){
        cout<<0<<endl; return;
    }
    if(N==2){
        cout<< (P[0]<P[1]? 0:1)<<endl; return;
    }
    vll A(N);
    REP(i, N){
        A[P[i]]=i;
    }
    A.push_back(INF);
    ll s=0, t=0;
    ll cnt = 0;
    while(s<N){
        while(t<N-1 && A[t+1]>A[t])
            t++;
        cnt = max(cnt, t-s+1);
        s = t+1;
        t = s;
    }
    cout<< N - cnt<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&P[i]);
        P[i]--;
    }
    solve(N, std::move(P));
    return 0;
}
