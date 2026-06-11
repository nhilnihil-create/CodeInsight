#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for ( ll i = 1; i * i <= n; ++i ) {
        if ( n % i != 0 ) continue;
        if ( n / i - 1 <= i ) break;
        ans += n / i - 1;
    }
    cout << ans << endl;
    return 0;
}
