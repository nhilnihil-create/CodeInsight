#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define countof(a) (sizeof(a)/sizeof((a)[0]))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define SP << " " <<

signed main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);

    ll AB[2], K; cin >> AB[0] >> AB[1] >> K;

    rep(i, K) {
        AB[i%2] = (AB[i%2] & 0xfffffffffffffffe) >> 1;
        AB[(i+1)%2] += AB[i%2];
    }

    cout << AB[0] SP AB[1] << endl;
}
