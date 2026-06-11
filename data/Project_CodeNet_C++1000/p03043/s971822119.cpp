#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n, k;
    cin >> n >> k;
    double ans = 0;
    REP(i,1,n+1){
        if(i >= k){
            ans += n-k+1.0;
            break;
        }else{
            ll x = ceil(log2((k+i-1)/i));
            ans += pow(0.5,x);
        }
    }
    ans /= (double)n;
    printf("%.10f\n",ans);
    return 0;
}