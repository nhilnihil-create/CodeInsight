#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    if(n==1&&m==1) ans = 1;
    else if(n==1||m==1) ans = n*m-2;
    else if(n==2||m==2) ans = 0;
    else ans = (n-2)*(m-2);
    COUT(ans);
    return 0;
}
