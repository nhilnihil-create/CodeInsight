#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<ll> a;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.pb(abs(k-num));
    }
    ll ans  = __gcd(a[0], a[1]);
    for(int i=2;i<n;i++){
        ans = __gcd(ans, a[i]);
    }
   cout<<ans<<'\n';

}

int main() 
{
    std::ios::sync_with_stdio(false); \
        std::cin.tie(NULL);
    int test;
   test =1;;
    while (test--) {
        solve();
    }
    return 0;
}