#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    int ans = mod;
    for(int i = 0; i < n; i++) cin >> h[i];
    sort(h.begin(),h.end());    
    for(int i = 0; i < n-k+1; i++){
        int can = h[i+k-1]-h[i];
        if(ans > can) ans = can;
    }
    cout << ans << endl;
    return 0;
}
