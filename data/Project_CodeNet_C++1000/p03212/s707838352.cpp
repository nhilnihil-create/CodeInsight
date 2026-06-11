/********include********/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#define popcount __builtin_popcount
using namespace std;

/***/
//#include <iomanip>
//#include <cmath>
#include <bits/stdc++.h>

/********define********/

#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define rrep(i,x) for(long long i=x-1;i>=0;i--)
#define rrepn(i,x) for(long long i=x;i>1;i--)
#define REP(i,n,x) for(long long i=n;i<x;i++)
#define REPN(i,n,x) for(long long i=n+1;i<x;i++)

#define pr printf
#define re return
#define mod 1000000007
//#define mod 998244353
#define INF 1e18+5//19桁
const double PI=3.14159265358979323846;
#define fi first
#define se second
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

typedef long long int ll;
typedef pair<long long, long long> P;


/********よく使う関数********/

// 素因数分解
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

// 約数列挙
vector<long long> calc_divisor(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

//最大公約数 複数個
int gcd(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = gcd(ret, v[i]);
	return ret;
}

//最小公倍数
int lcm(int x, int y) { return x / gcd(x, y) * y; }

//最小公倍数 複数個
int lcm(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = lcm(ret, v[i]);
	return ret;
}

/********変数宣言********/
//vector<long long> g[200020];
vector<pair<long long,long long>> g[200020];
ll s[200020];
bool used[200020];
bool dp[100005];
ll answer;

ll A,B,C,D,H,K,M,N,Q,T,W,X,Y;
double dA,dB,dC,dH,dK,dM,dN,dQ,dT,dW,dX,dY;
ll counter;
void solve(ll curre, ll flg){
    if(curre > N)return;
    //if(flg && 0b111)counter++;
    if(flg == 0b111)counter++;
    solve(curre*10+7,flg | 0b001);
    solve(curre*10+5,flg | 0b010);
    solve(curre*10+3,flg | 0b100);

}
int main()
{
	cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    counter=0;
    solve(0,0);
    cout << counter;
    re 0;
    
}
