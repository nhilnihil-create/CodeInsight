#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template <class T> void swap(T& a, T& b) { T t = std::move(a); a = std::move(b); b = std::move(t); }

// 最大公約数
ll gcd(ll a, ll b)
{
    if(a%b == 0){
        return(b);
    }
    else{
        return(gcd(b, a%b));
    }
}

// 最小公倍数
ll lcm(ll a, ll b)
{
    return a  / gcd(a, b) * b;
}

int main(void)
{
    ll N, M, g, l, i, j, k, judge=1;
    string S, T;

    cin >> N >> M >> S >> T;

    g = gcd(N,M);
    l = lcm(N,M);

    j = 0; k = 0;
    for(i=1; i<=g; i++){
        if(S[j] != T[k]){
            judge = 0;
            break;
        }

        j += (N/g);
        k += (M/g);
    }

    if(judge==1) cout << l << endl;
    else cout << -1 << endl;

    return 0;
}