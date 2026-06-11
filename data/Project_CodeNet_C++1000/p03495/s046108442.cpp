#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);

    int i;
    for(i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> t(n);
    for(i = 0; i < n; i++) {
        t[s[i]-1]++;
    }

    sort(t.begin(), t.end(), greater<int> ());

    int ans = 0;
    for(i = k; i < n; i++) {
        ans += t[i];
    }
    cout << ans << endl;
}
