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

ll f(ll n){
    ll res=0;
    while(n>0){
        res+=n%10;
        n/=10;
    }
    return res;
}

double g(ll n){
    return (double)n/f(n);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<ll> res;
    ll base=1;
    
    rep(i,15){
        rep1(j,149){
            res.push_back(base*(j+1)-1);
        }
        base*=10;
    }
    
    sort(all(res));
    res.erase(unique(all(res)),res.end());
    
    for(ll i=0;i<res.size();i++){
        for(ll j=i+1;j<res.size();j++){
            if(g(res[i])>g(res[j])){
                res.erase(res.begin()+i--);
                break;
            }
        }
    }
    
    ll K;
    cin>>K;
    for(ll i=0;i<K;i++) cout1(res[i]);
}