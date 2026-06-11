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

ll gcd (ll a, ll b){ return b == 0? a : gcd(b, a % b); }
ll lcm (ll a, ll b){ return a * (b / gcd(a, b));}

void solve(long long N, long long M, std::string S, std::string T){
    ll L = lcm(N, M);
    ll a = L/N, b = L/M;
    ll c = gcd(M, N);
    ll n = N/c, m = M/c;
    for(ll p=0; p < c; p++){
        if(S[p*n]!= T[p*m]){
            cout << -1 << endl; 
            return;
        }
    }
    cout << L << endl;  
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(N, M, S, T);
    return 0;
}
