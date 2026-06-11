#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int>h(n);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    int ans = MOD;
    for(int i=0;i<=n-k;i++){
        int x=h[i+k-1]-h[i];
        ans=min(ans,x);
    }
    cout << ans << endl;
}