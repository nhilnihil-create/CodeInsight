#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define mkp make_pair
#define fi first
#define se second
#define pt(num) cout << num << "\n"
#define mCalc(a, s, b) (a)=((a)s(b)+MOD)%MOD
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 101010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll mPow(ll x, ll n) {
    ll res=1;
    while(n>0) {
        if(n&1) mCalc(res, *, x);
        mCalc(x, *, x);
        n>>=1;
    }
    return res;
}

ll dp[22][2100000];

int main(void) {
    ll N;
    cin >> N;
    ll i;
    ll s[MAX];
    ll fa[MAX];
    ll res=0;
    fa[0]=1;
    for(i=1; i<=N; i++) {
        fa[i]=i*fa[i-1]%MOD;
        s[i]=(s[i-1]+mPow(i, MOD-2))%MOD; //mPow(i, MOD-2):1/iの逆元、s[i]:1/1,1/2,...1/iの和
    }
    
    for(i=0; i<N; i++) {
        ll a;
        cin >> a;
        mCalc(res, +, (s[i+1]+s[N-i]-1)%MOD*a%MOD);
    }
    
    pt(res*fa[N]%MOD);
    
}








