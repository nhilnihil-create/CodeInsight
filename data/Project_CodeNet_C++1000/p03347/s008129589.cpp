#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    if(a.front()) {
        cout << -1 << endl;
        return 0;
    }

    ll sum = 0;
    for(int i = 1; i < n; i++) {
        while(i < n-1 && a[i] < a[i + 1]) {
            if(a[i + 1] - a[i] != 1) {
                cout << -1 << endl; return 0;
            }
            i++;
        }
        sum += a[i];
        // cerr << i << endl;
    }
    cout << sum << endl;
}
