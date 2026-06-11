#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

ll x(ll x){
    ll res = 0;
    for(ll i=(x/4)*4;i<=x;i++) res ^= i;
    return res;
}

int main(){
    ll a,b;
    cin >> a >> b;
    if(a==0) cout << x(b) << endl;
    else cout << (x(a-1) ^ x(b)) << endl;
    return 0;
}