#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

ll pow(ll now, ll x){
    if(now==x) return 1;
    return 2*pow(now+1,x);
}
int main(){
    int n,m; cin>>n>>m;
    cout<<(1900*m+100*(n-m))*pow(2,m)<<endl;
}