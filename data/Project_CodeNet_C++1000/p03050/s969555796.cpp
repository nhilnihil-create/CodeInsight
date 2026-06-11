#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
    ll n ; cin >> n;
    ll ans = 0;
    for(int i=1;i<(int)(sqrt(n)+1);i++){
        if(n%i != 0) continue;
        ll m = (n/i) - 1;
        if(1<=i && i<=m-1) ans+= m;       
    }
    cout << ans << endl;
}