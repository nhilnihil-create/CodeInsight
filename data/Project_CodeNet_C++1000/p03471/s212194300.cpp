#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i <= n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    int n; cin >> n;
    long long y; cin >> y;
    long long sum = 0;
    bool ans = true;

    rep(i,n) {
        rep(j,n) {
            sum = 10000*i + 5000*j + 1000*(n-i-j);
            if(sum==y && n>=i+j) {
                ans = false;
                cout << i << ' ' << j << ' ' << n-i-j << endl;
                break;
            }
        }
        if(ans == false) break;
    }

    if(ans) cout <<"-1 -1 -1" << endl;
}