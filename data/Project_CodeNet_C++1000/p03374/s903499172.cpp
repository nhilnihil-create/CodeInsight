#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <cmath>
#include <math.h>
#include <array>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);
#define DEBUG_VIS(x) cerr<<"vis "<<x<<endl;
#define DEBUG_REACH cerr<<"reach here"<<endl;
#define DEBUG_SEQ(x) cerr<<x<<" ";
#define SET_ZERO(x) memset(x,0,sizeof(x));
#define SET_NEGONE(x) memset(x,-1,sizeof(x));
#define SET_INF(x) memset(x,127,sizeof(x));
#define SET_NEGINF(x) memset(x,128,sizeof(x));
#define IS_INF(x) x < 2100000000
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const int maxn = 1e6 + 10;
template <class T> T mymin(const T a,const T b){return a < b ? a : b;}
template <class T> T mymax(const T a,const T b){return a > b ? a : b;}
ll N,C;
ll dis[maxn],val[maxn],f[maxn],g[maxn],f1[maxn],g1[maxn];
ll sum1[maxn],sum2[maxn];

int main(){
    FAST_IO
    cin>>N>>C;
    ll ans = 0;
    for(int i = 1; i <= N; i++) cin>>dis[i]>>val[i];
    for(int i = 1; i <= N; i++) {
        sum1[i] = sum1[i - 1] + val[i];
        f[i] = sum1[i] - dis[i];
        f1[i] = max(f[i],f1[i - 1]);
        ans = max(ans,f[i]);
    }
    for(int i = N; i >= 1; i--) {
        sum2[i] = sum2[i + 1] + val[i];
        g[i] = sum2[i] - (C - dis[i]);
        g1[i] = max(g1[i + 1],g[i]);
        ans = max(ans,g[i]);
    }
    for(int i = 1; i <= N; i++) ans = max(ans,g1[i + 1] + f[i] - dis[i]);
    for(int i = 1; i <= N; i++) ans = max(ans,f1[i - 1] + g[i] - (C - dis[i]));
    cout<<ans<<endl;
    return 0;
}
