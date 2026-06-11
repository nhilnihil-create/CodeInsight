#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807


int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    reverse(a.begin(),a.end());
    vector<ll> asum(n);
    asum[0] = a[0];
    for(int i = 1; i < n; i++){
        asum[i] = asum[i-1] + a[i];
    }


    ll ans = LLINF;
    for(int i = 1; i <= n; i++){
        bool overflow = false;
        ll cost = (i+n)*x;
        cost += 5*asum[i-1];
        ll prevcost = cost;
        ll num = 2*i-1;
        ll cnt = 1;
        while(num < n){
            ll coef = 2*cnt+3;
            cost += coef*(asum[num]-asum[num-i]);
            if(prevcost > cost){overflow = true;}
            else{prevcost = cost;}
            cnt++;
            num += i;
        }
        if(overflow){continue;}
        cost += (2*cnt+3)*(asum[n-1]-asum[num-i]);
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}
