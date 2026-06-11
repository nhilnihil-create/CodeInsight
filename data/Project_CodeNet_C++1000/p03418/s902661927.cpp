#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
    int n,k; cin >> n >> k;
    ll ans = 0;
    for(int b = k+1; b <= n; ++b){
        ans += (b-k)*(n/b);
        ans += max(0, (n%b) - k + 1);
        if(k == 0) ans--;
    }
    cout << ans;
}