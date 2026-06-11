#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll k;
    cin>>k;
    ll ma=3,mi=2;
    ll a[k];
    for(int i=0;i<k;i++)cin>>a[i];
    reverse(a,a+k);
    for(int i=1;i<k;i++){
        mi=(mi+a[i]-1)/a[i];
        ma=ma/a[i];
        mi*=a[i];
        ma*=a[i];
        ma+=a[i]-1;
    }
    reverse(a,a+k);
    ll num=mi,m=ma;
    for(int i=0;i<k;i++){
        num/=a[i];
        num*=a[i];
        m/=a[i];
        m*=a[i];
    }
    if(m==2&&num==2)cout << mi<<" "<<ma<<endl;
    else cout<< -1<<endl;
    return 0;
}
