#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n;
    vector<ll> nums, left(n,0), right(n,0);
    for (ll i=0; i<n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    ll res = nums[0];
    for (ll i=0; i<n; i++) {
        res = __gcd(nums[i],res);
        left[i] = res;
    }
    res = nums[n-1];
    for (ll i=n-1; i>=0; i--) {
        res = __gcd(nums[i],res);
        right[i] = res;
    }
    vector<ll> gcds;
    for (ll i=0; i<n; i++) {
        if (i==0) gcds.push_back(right[i+1]);
        else if (i==n-1) gcds.push_back(left[i-1]);
        else gcds.push_back(__gcd(left[i-1],right[i+1]));
    }
    sort(gcds.begin(),gcds.end());
    cout << gcds[n-1];
    return 0;
}