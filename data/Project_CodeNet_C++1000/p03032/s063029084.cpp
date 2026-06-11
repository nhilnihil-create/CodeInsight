#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector v(n,0L);
    for (int i=0; i<n; i++) cin >> v[i];

    long ans = 0;
    for (int i=0; i<=k; i++) {
        for (int j=0; j<=k; j++) {
            if (i+j>n || i+j>k) continue;
            long sum = 0;
            priority_queue<long, vector<long>, greater<>> pq;

            for (int l=0; l<i; l++) {
                sum += v[l];
                pq.emplace(v[l]);
            }

            for (int l=0; l<j; l++) {
                sum += v[n-1-l];
                pq.emplace(v[n-1-l]);
            }

            ans = max(ans, sum);
            
            for (int l=k; l>i+j; l--) {
                if (pq.empty()) break;
                sum -= pq.top(); pq.pop();
                ans = max(ans, sum);
            }

        }
    }

    cout << ans << endl;
}
