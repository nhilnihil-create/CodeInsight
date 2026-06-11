#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long int ll;
ll n, m;
int T;
ll max_l(ll x, ll y) { return x > y?x:y; }
ll f(ll n) {
    switch (n % 4) {
    case 0:return n;
    case 1:return 1;
    case 2:return n + 1;
    case 3:return 0;
    }
}

int main()
{
    cin >> n >> m;
    ll ans = f(max_l(0, n - 1)) ^ f(m);
    cout << ans<< endl;
   
    return 0;
}