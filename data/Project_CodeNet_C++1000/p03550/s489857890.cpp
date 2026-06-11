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
    ll n,z,w;
    cin>>n>>z>>w;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    cout << ((n>1)?(max(abs(a[n-1]-w),abs(a[n-1]-a[n-2]))):abs(a[0]-w)) <<endl;
    return 0;
}
