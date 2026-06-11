#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n,k; cin >> n >> k;
    ll m0 = 0,m2 = 0;
    for(int i = 1; i <= n; i++){
        if(i%k == 0) m0++;
        if(i%k == k/2) m2++;
    }
    ll ans = m0*m0*m0;
    if(k % 2 == 0) ans += m2*m2*m2;

    cout << ans << endl;

    return 0;
}