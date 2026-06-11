#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<int> b(m-1);
    for(int i = 0; i < m-1; i++) b[i]=a[i+1]-a[i];
    sort(b.begin(),b.end());
    ll ans =0;

    if(n>=m){
        cout << 0 << endl;
    }
    else{
        for(int i = 0; i < m-n; i++) {
            ans += b[i];
        }
        cout << ans << endl;
    }
    return 0;
}