#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const ld pi=3.14159265358979323846;
 
int main() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    ll sum=0,cnt=0;
    rep(i,n) sum+=a[i];
    if (sum==x){
        cout<<n<<endl;
        return 0;
    }
    else{
        rep(i,n-1){
            if (a[i]<=x){
                x-=a[i];
                cnt++;
            }
        }
    cout<<cnt<<endl;
    }
}