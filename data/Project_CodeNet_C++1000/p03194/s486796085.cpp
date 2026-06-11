#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i=a; i<n; i++)
#define RREP(i, a, n) for(ll i=n-1; i>=a; i--)
typedef long long ll;
const ll mod =1e9+7;
const ll inf =1e18;
using namespace std;

ll n, p;
vector<pair<ll, ll>> prime_factor(ll n) {
    vector<pair<ll, ll>> vp;

    for (ll i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            vp.emplace_back(i, 0);

            do {
                vp[vp.size() - 1].second++;
                n /= i;
            } while (n%i == 0);
        }
    }

    if (n != 1) vp.emplace_back(n, 1);
    return vp;
}
int main(){
    cin>>n>>p;

    if(n==1){
        cout<<p<<endl;
        return 0;
    }
    else if(p==1 || n>50){
        cout<<1<<endl;
        return 0;
    }

    vector<pair<ll, ll>> pf=prime_factor(p);

    ll a[51];
    ll cnt=0;
    REP(i, 0, n){
        a[i]=1;
    }
    RREP(i, 0, pf.size()){
        REP(j, 0, pf[i].second){
            a[cnt]*=pf[i].first;
            cnt=(cnt+1)%n;
        }
    }

    ll gcd=__gcd(a[0], a[1]);
    REP(i, 2, n){
        gcd=__gcd(gcd, a[i]);
    }
    cout<<gcd<<endl;
    return 0;
}