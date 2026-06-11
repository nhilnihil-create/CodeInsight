#define _USE_MATH_DEFINES    
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <complex>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <bitset>
#include <limits>
#include <algorithm>
#include <array>
#include <random>
#include <complex>
#include <regex>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define quickIO()   {cin.tie(0);    cout.sync_with_stdio(false);}
#define rep(i,n)    for(ll i=0; i<(ll)n; i++)
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define fcout cout << fixed << setprecision(10) 
const ll inf = 1e18;
const ll mod = 1e9 +7;
     
ld sqrtld(ld x){
    ld left = 0, right = x;
    rep(i, 100){
        ld mid = (left + right)/2;
        if (mid*mid <= x)   left =mid;
        else    right = mid;
    }
    return left;
}

ll gcd(ll a, ll b){
    if(b>a){
        ll c =b; b=a;   a=c;
    }
    ll d = a%b;
    if(d==0){
        return b;
    }else if(d==1){
        return 1;
    }else{
        gcd(b,d);
    }
}


ll cul(ll n){
    return (n-1)*n/2;
}

ll a[200010];
ll b[200010];
int main (){
    ll n;  cin >> n;
    rep(i,n) cin >> a[i] >> b[i];
    ll ans=0;
    rep(i,n){
        if(a[i]!=b[i])  break;
        if(i==n-1){
            cout << ans << endl;
            return 0;
        }
    }
    ll m=inf;
    rep(i,n){
        ans += a[i];
        if(a[i]> b[i]){
            m = min(m, b[i]);
        }
    }
    ans -= m;
    cout << ans << endl;
}


