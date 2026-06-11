#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int x[m];
    for(int i = 0; i < m; ++i) cin >> x[i];
    if(n >= m) {
        cout << 0 << '\n';
        return 0;
    }
    sort(x, x+m);
    priority_queue<int> pq;
    for(int i = 0; i < m-1; ++i) {
        pq.push(x[i+1] - x[i]);
    }
    int ans = x[m-1] - x[0];
    while(!pq.empty() && n != 1) {
        int diff = pq.top();
        pq.pop();
        ans -= diff;
        n--;
    }

    cout << ans << '\n';
    
    return 0;
}
