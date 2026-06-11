#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(100001);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x<100001) a[x]++;
        else a[0]++;
    }
    int ans=0;
    for(int i = 0; i < 100001; i++) {
        if(a[i]>=i) ans += a[i]-i;
        else ans += a[i];
    }
    cout << ans << endl;

    return 0;
}