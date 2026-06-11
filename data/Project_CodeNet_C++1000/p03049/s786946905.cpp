//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
#define LL long long
#define LD long double
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pii pair<int,int>
#define pli pair<LL,int>
#define pil pair<int,LL>
#define pll pair<LL,LL>
#define ff first
#define ss second
#define pb push_back
#define BTW(x,a,b) ((a) <= (x) && (x) <= (b))
#define _eq(a,b) (fabs((a)-(b)) < EPS)
#define _lt(a,b) (fabs((a)-(b)) > EPS && a < b)
#define _gt(a,b) (fabs((a)-(b)) > EPS && a > b)
#define _lte(a,b) !_gt(a,b)
#define _gte(a,b) !_lt(a,b)
const vector<pii> XY = {pii(0,-1),pii(0,1),pii(-1,0),pii(1,0)};
const LD EPS = 1e-8;
const LD PI = acos(-1.0L);
const LL INFLL =  4e18;
const int INF  =  2e9;
const int MOD  =  1e9 + 7;
//#define int long long

// read / write
template<typename T> void read(T& t) { cin >> t; }
template<typename T, typename ... U> void read(T& t, U& ... u) { read(t); read(u ...); }
template<typename T> void write(T t) { cout << t; }
template<typename T, typename ... U> void write(T t, U ... u) { write(t); write(u ...); }



// ------------------------------------------------- Vs
const int LOGN    =  16              + 1;
const int MAXN1   =  3e5            + 3;
const int MAXN2   =  8            + 3;
// ------------------------------------------------- Fs
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); write(fixed, setprecision(12));
    int n; read(n);
    int n1=0,n2=0,n3=0;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        string s; read(s);
        for(int j = 0; j + 1 < sz(s); ++j) ans += s[j]=='A'&&s[j+1]=='B';
        bool b1 = s.back()=='A';
        bool b2 = s.front()=='B';
        if(b1&&b2) ++n1;
        else if(b1) ++n2;
        else if(b2) ++n3;
    }
    
    if(n1 == 0) ans += min(n2,n3);
    else{
        ans += n1 - 1;
        if(n2) ++ans,--n2;
        if(n3) ++ans,--n3;
        ans += min(n2,n3);
    }

    write(ans, "\n");
    return 0;
}