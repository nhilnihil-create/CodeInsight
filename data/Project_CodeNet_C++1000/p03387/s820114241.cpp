#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    const int p = 3;
    vector<int> x(p);
    for (int i = 0; i < p; i++) cin >> x[i];
    sort(x.begin(), x.end());
    
    int diff = x[2] - x[0] + x[2] - x[1];
    int ans;
    if (diff % 2 == 0) {
        ans = diff / 2;
    }
    else {
        ans = (diff + 1) / 2 + 1;
    }
    cout << ans << endl;
    return 0;
}