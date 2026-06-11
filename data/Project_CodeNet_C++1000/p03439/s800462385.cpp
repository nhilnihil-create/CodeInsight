#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX=1001001;
const ll MOD=1000000007;
int main()
{
    ll n;
    cin >> n;
    ll r=0;
    ll l=n+1;
    cout<<r<<endl;
    string s;
    cin>>s;
    if (s=="Vacant") {
        return 0;
    }
    string a=s;
    ll q=19;
    while (q--) {
        ll m=(r+l)/2;
        cout<<m<<endl;
        cin>>s;
        if (s=="Vacant") {
            return 0;
        }
        if (s==a) {
            if ((m-r)%2) {
                l=m;
            }
            else {
                r=m;
                a=s;
            }
        }
        else {
            if ((m-r)%2) {
                r=m;
                a=s;
            }
            else {
                l=m;
            }
        }
    }
}
