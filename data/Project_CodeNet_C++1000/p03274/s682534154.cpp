#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define forn(b) for(int i = 0; i < b; i++)
#define rforn(b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
signed main(){
    speed;
    int n, k; cin >> n >> k;
    vi v(n);
    forn(n) cin >> v[i];
    int ans = LONG_LONG_MAX;
    int l = 0, r = 0;
    r = l + k - 1;
    ll sum1 = 0, sum2 = 0;
    while(r < n && l < n) {
        if(v[l] < 0 && v[r] > 0) {
            sum1 += abs(v[r]) + abs(2 * v[l]);
            sum2 += abs(2 * v[r]) + abs(v[l]);
            ans = min(ans, sum1);
            ans = min(ans, sum2);
        }
        else if(v[l] > 0) {
            sum1 += abs(v[r]);
            ans = min(ans, sum1);
        } else if(v[r] < 0) {
            sum2 += abs(v[l]);
            ans = min(ans, sum2);
        }
        if(v[l] > 0 && v[r] > 0) break;
        sum1 = 0, sum2 = 0;
        l++;
        r++;
    } 
    if(ans == LONG_LONG_MAX) ans = 0;
    cout << ans;
}