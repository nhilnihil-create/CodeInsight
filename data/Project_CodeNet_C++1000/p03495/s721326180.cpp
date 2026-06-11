#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     
    int n, k; cin >> n >> k;
    const int p = 200010;
    vector<int> num(p,0);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        num[a]++;
    }
    sort(num.begin(), num.end(), greater<int>());

    int ans = 0;
    for (int i = k; i < p; i++) {
        if (num[i] == 0) break;
        ans += num[i];
    }
 
    cout << ans << endl;
    return 0;
}