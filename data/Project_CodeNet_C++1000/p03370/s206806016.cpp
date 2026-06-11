#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    for (int i=0; i<n; i++) cin >> m[i];
    int min_m = *min_element(m.begin(), m.end());
    int ans = n + (x - accumulate(m.begin(), m.end(), 0))/min_m;
    cout << ans << endl;
    return 0;
}