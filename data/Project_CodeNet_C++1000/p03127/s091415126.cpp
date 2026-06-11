#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;
    rep(i, n) {
        int a;
        cin >> a;
        q.push(a);
    }
    while (q.size() > 1) {
        int m = q.top();
        q.pop();
        rep(i, q.size()) {
            int a = q.top();
            q.pop();
            if (a % m != 0) {
                a %= m;
                q.push(a);
            }
        }
        q.push(m);
    }
    cout << q.top() << endl;
}