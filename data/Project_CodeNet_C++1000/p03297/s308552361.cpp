#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int T;

bool check(ll a,ll b,ll c,ll d){
    if(a<b||b>d) return false;
    if(c>=b) return true;
    a%=b;
    ll g=__gcd(b,d);
    ll x=b-g+(a%g);
    return (x<=c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>T;
    rep(i,T){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        cout1((check(a,b,c,d)?"Yes":"No"));
    }
}