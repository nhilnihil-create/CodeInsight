#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0);

void yakusuu(ll n) {
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) {
            if(abs(i-n/i)>=2) {
                if(i>n/i) ans += i-1;
                else ans += n/i-1;
            }
        }
    }
}

signed main(){
    cin >> N;
    yakusuu(N);
    cout << ans << endl;
    return 0;
}