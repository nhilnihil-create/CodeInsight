#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,tot;
    cin >> n >> tot;
    vector<int> a(n);
    for ( int i=0; i<n; i++ ) cin >> a[i];
    sort(a.begin(),a.end());
    
    int ans=0;
    for ( int i=0; i<n; i++ ) {
        if ( tot<=0 ) break;
        if ( tot>=a[i] ) ans++;
        tot-=a[i];
    }
    if ( tot>0 ) ans--;
    cout << ans << '\n';
    return 0;
}