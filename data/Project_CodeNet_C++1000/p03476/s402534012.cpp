#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 100000;

ll N, ans=0, tmp=0;
vector<ll> S(MAXN, 0);

bool sosuu(ll num) {
    for(int i=2;i*i<=num;i++) {
        if(num%i==0) {
            return 0;
        }
    }
    return 1;
}

ll judgefunc(ll num) {
    if(sosuu(num)&&sosuu((num+1)/2)) return 1;
    return 0;
}

void prepairfunc() {
    S[1] = 0;
    for(int i=1;i<50000;i++) {
        S[2*i+1] = S[2*i-1] + judgefunc(2*i+1);
    }
}

signed main(){
    prepairfunc();
    cin >> N;
    for(int i=0;i<N;i++) {
        ll l, r;
        cin >> l >> r;
        if(l==1) cout << S[r] << endl;
        else cout << S[r]-S[l-2] << endl;
    }
    return 0;
}