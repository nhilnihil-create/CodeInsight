//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
double pow(double x, ll ntimes) {
    double ret = 1.0;
    while (ntimes > 0) {
        if ((ntimes & 1) == 1) {
            ret = ret * x;
        }
        x = x * x;
        ntimes >>= 1;
    }
    return ret;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,d;
    cin >> n >> m >> d;
    ll sum = 0;
    if(d==0){
        sum = n;
    }else if(n-d+1<=d){
        sum = n;
        sum -= d - (n-d+1) +1;
    }else{
        sum += 2*d;
        sum += 2*(n-2*d);
    }
    ll x = sum * (m-1);
    ll y = n*n;
    double ans = (double)x/y;
    printf("%.10f\n", ans);
    return 0;
}