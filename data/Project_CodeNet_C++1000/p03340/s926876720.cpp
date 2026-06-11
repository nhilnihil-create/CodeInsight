#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll a[200010];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)cin >> a[i];
    ll res = 0;
    int j = 0;
    ll now = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && (now ^ a[j]) == (now + a[j])) {
            now += a[j];
            ++j;
        }
        res += (j - i);
        if (j == i) ++j;
        else now -= a[i];
    }

    cout << res << endl;

    return 0;
}
