//----------------------------おまじない
#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
//----------------------------
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>0;i--)
#define I(n) scanf("%d", &(n))
#define LL(n) scanf("%lld", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#define eb(i,j) emplace_back((i),(j))
#include <bits/stdc++.h>
using namespace std;
//------------------------------typedef集
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vvi> vvvi;
typedef long long ll;
const int mod = 1000000009;

ll n,x,xi[200010],rui[500010];
ll ret;

int main(){
    LL(n); LL(x); REP(i,n) LL(xi[n-1-i]);
    REP(i,n) rui[i+1] = rui[i] + xi[i];
    FOR(i,n,n+300000) rui[i+1] = rui[i];
    ll col_cost = x*n;
    ret = LLONG_MAX;
    
    FOR(j,1,n+1){
        ll temp = j*x;
        REP(k,n/j+1){
            temp += (rui[j*(k+1)] - rui[j*k]) * (k ? 2*k+3 : 5);
            //cerr << j << " " << k << " " << temp << endl;
            if (temp < 0) break;
        }
        if (temp > 0 && ret > temp) ret = temp;
    }
    cout << ret + col_cost << endl;
}