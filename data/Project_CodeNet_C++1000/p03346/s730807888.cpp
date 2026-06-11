#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dbg(x) cerr << #x << ": " << x << '\n'
#define fast_io() ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second

signed main() {
    fast_io();
    int n;
    cin >> n;
    vector<int> ind(n);
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        p--;
        ind[p] = i;
    }
    int mx = 0, len = 0;
    for(int i = 0; i < n; i++){
        if(i == 0 || ind[i] > ind[i - 1]) len++; else len = 1;
        mx = max(mx, len);
    }
    cout << n - mx;
    return 0;
}
