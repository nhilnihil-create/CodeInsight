#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0 ;i < n ;i++)
        cin >> a[i];


    int ans = 0;
    for (int i = 0 ;i <= n ;i++) {
        for (int j = i ;j < n ;j++) {
            int c = i + n - j - 1;
            if (c > k) continue;
            int s = 0;
            priority_queue<int> q;

            for (int k = 0 ;k < n ;k++) {
                if (k < i || k > j) {
                    s += a[k];
                    if (a[k] < 0)
                        q.push(-a[k]);
                }
            }

            int rem = k - c;
            while (rem > 0 && q.size()) {
                s += q.top();
                q.pop();
                rem--;
            }

            ans = max(ans , s);
        }
    }

    if (n <= k) {
        int s = 0;
        priority_queue<int> q;
        for (int i = 0 ;i < n ;i++) {
            s += a[i];
            if (a[i] < 0)
                q.push(-a[i]);
        }

        int rem = k - n;
        while (rem > 0 && q.size()) {
            s += q.top();
            q.pop();
            rem--;
        }

        ans = max(ans , s);
    }

    cout << ans;
}
