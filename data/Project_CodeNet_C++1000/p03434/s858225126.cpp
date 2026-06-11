#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, n, ans=0;
    cin >> n;
    vector<int> d(n);

    for(i=0; i<n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());

    for(i=0; i<n; i++) {
        if (i%2) ans -= d[i];
        else ans+=d[i];
    }

    cout << abs(ans) << endl;
}