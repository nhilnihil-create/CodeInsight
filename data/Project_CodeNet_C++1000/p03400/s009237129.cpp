#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>
#include<regex>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<ctime>
#include<vector>
#include<bitset>
#include<cstdio>
#include<numeric>
#include<utility>
#include<sstream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<map>
#include<functional>
#include<unordered_map>
#define _USE_MATH_DEFINES
#define inf 999999999999999999
#define rep(i,n,m) for(lli i=(lli)(n);i<(lli)(m);++i)
#define reep(i,n,m) for(int i=(int)(n);i<=(int)(m);++i)
#define per(i,m,n) for(lli i=(int)(m)-1;i>=(int)(n);--i)
#define st(n) sort(n.begin(), n.end())
#define rev(n) reverse(n.begin(),n.end())
#define ou(S) cout << S << endl
#define pb(n) push_back(n)
#define ue(N) N.erase(unique(N.begin(),N.end()),N.end());
#define nou(S) cout << S
#define hou(S) cout << setprecision(30) << S << endl
#define vec(K,L,N,S) vector<L> K(N,S)
#define dv(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define tv(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define maxx 5100000
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define endl "\n"
typedef long long int lli;
typedef unsigned long long int uli;
const uli mod = 1e9 + 7;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, x, sum = 0;
    cin >> n >> d >> x;
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        if(a ==1)
            sum += d;
        else sum += d / a + 1;
        if(d % a == 0&&a!=1)
            --sum;
    }
    cout << sum + x << endl;
}