#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int a[100005];
    int b[100005];
    int c[100005];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];
    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);
    ll ans=0;
    for(int i=0; i<n; i++){
        int x=b[i];
        long long k1=lower_bound(a,a+n,x)-a;
        long long k2=n-(upper_bound(c,c+n,x)-c);
        ans += k1*k2;
    }
    cout << ans << endl;

}