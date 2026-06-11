#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
int n, m;
ll a[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++){a[i] += a[i-1]; a[i]%= m;}
    map<ll, ll> mp;
    ll res = 0;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        res += mp[a[i]]; mp[a[i]]++;
    }
    cout << res << endl;
    return 0;
}
