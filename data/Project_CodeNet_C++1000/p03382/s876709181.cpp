#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1e5 + 5;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = *max_element(a, a + n), dist = 1e9, x;

    for (int i = 0; i < n; i++) {
        if (a[i] == mx)
            continue;
        
        int cur_dist;
        if (mx % 2) {
            if (a[i] <= mx / 2)
                cur_dist = mx / 2 - a[i];
            else
                cur_dist = a[i] - mx / 2 - 1;
        }
        else {
            cur_dist = abs(a[i] - mx / 2);
        }

        if (cur_dist < dist) {
            dist = cur_dist;
            x = a[i];
        }
    }

    cout << mx << " " << x;

    return 0;
}