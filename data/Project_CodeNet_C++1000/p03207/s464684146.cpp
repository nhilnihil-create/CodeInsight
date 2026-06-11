#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;
ll x, y, z, l, m, n, r, q, k;

void solve() {
    cin>>n;
    ll sum=0, m = 0;
    for(int i=0;i<n;i++){
        ll num;
        cin>>num;
        sum+=num;
        m = max(m, num);
    }
    cout<<sum-m/2<<'\n';

}

int main() 
{
    std::ios::sync_with_stdio(false); \
        std::cin.tie(NULL);
    int test;
    test = 1;
    while (test--) {
        solve();
    }
    return 0;
}