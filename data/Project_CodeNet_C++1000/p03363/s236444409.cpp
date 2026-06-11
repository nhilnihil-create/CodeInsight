#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<long long,long long> mp;
    long long sum=0;
    mp[sum]++;
    long long ans=0, a;
    for ( int i=0; i<n; i++ ) {
        cin >> a;
        sum+=a;
        if ( mp.count(sum) ) ans+=mp[sum];
        mp[sum]++;
    }
    cout << ans << '\n';
    return 0;
}