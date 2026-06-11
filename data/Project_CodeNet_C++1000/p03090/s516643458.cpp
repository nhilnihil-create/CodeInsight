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


void solve(long long N){
    vector<vll> G(N);
    if(N % 2){
        REP(i, N){
            REP(j, N){
                if(i==j) continue;
                if(i+j==N-2) continue;
                G[i].push_back(j); 
            }
        }
    }else{
        REP(i, N){
            REP(j, N){
                if(i==j) continue;
                if(i+j==N-1) continue;
                G[i].push_back(j); 
            }
        } 
    }
    ll num=0;
    REP(i, N) num+= G[i].size();
    num/=2;
    cout<<num<<endl;
    REP(i, N){
        for(auto j:G[i]){
            if(i<j) cout<<i+1<<" "<<j+1<<endl;
        }
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
