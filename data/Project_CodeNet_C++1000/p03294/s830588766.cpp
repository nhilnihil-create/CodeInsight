#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(a[i]-1);
    }
    cout << ans << endl;
}