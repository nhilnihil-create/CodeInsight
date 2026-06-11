#pragma gcc optimize("Ofast")

#include <iostream>
using namespace std;
typedef int64_t lld;
#define jizz cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

// code starts here
const int mod = 1000000007;
int invs[100001]={0, 1};
signed main(){jizz
    int n;
    lld f = 1, ans = 0, cnt = 0;
    cin >> n;
    for(int i = 2; i <= n; i++)
        invs[i] = (mod-(lld)(mod/i)*invs[mod%i]%mod);
    for(int i = 1; i <= n; i++)
        (invs[i] += invs[i-1])%=mod, f = f*i%mod;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ans = (ans + (lld)(invs[i]+invs[n+1-i]-1)*x)%mod;
    }
    cout << ans*f%mod << endl;
}
