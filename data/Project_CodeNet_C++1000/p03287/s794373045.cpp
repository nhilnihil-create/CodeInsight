#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    long long n, i, k, sum = 0, num;
    cin >> n >> k;
    map<ll, ll> f;
    f[sum]++;
    for(i = 1; i <= n; i++) {
        cin >> num;
        sum = (sum + num%k)%k;
        f[sum]++;
    }
    sum = 0;
    for(map<ll,ll>::iterator it = f.begin(); it != f.end(); it++) {
        ll x = it->second;
        sum += (x*(x - 1))/2;
    }
    cout << sum << "\n";
    return 0; 
}