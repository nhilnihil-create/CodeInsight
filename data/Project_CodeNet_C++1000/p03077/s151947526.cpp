#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {

    ll n,a[5]; cin >> n >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a,a+5);
    ll ans = 0;

    if(n%a[0] != 0) ans ++;
    ans += n/a[0] + 4;
    cout << ans;


    return 0;
}
