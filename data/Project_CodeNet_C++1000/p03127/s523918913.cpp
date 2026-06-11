#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;
int x, y, z, l, m, n, r, q, k;

void solve() {
    cin>>n;
    cin>>r>>q; int ans = __gcd(r, q);
    for(int i=2;i<n;i++){
        cin>>r;
        ans = __gcd(r, ans);

    }
    cout<<ans<<'\n';

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