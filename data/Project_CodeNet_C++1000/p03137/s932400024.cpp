#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
//const int MOD = 1e9+7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), d(m-1);
    for(int i=0; i<m; ++i)
        cin >> a[i];
    
    if(n>=m){
        cout << 0;
        return 0;
    }

    sort(a.begin(), a.end());

    for(int i=0; i<m-1; ++i)
        d[i] = a[i+1]-a[i];
    
    sort(d.begin(), d.end());

    ll ans = 0;
    for(int i=0; i<m-n; ++i)
        ans += d[i];
    cout << ans;
    return 0;
}
