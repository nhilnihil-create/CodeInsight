#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
const int maxn = 10000001;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<ll,int>mp;
    mp[0] = 1;
    ll cur = 0;
    ll ans = 0;
    f(n) {
        ll x;
        cin >> x;
        cur += x;
        ans += mp[cur];
        mp[cur]++;
    }
    cout << ans << '\n';
}  