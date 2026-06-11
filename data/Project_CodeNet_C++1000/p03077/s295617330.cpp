#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(void) {
    long long n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;
 
    long long ans;
    ans = max({(n-1)/a,(n-1)/b,(n-1)/c,(n-1)/d,(n-1)/e})+5;
    cout << ans << endl;
 
    return 0;
}