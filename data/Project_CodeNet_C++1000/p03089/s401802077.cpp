#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N); for (int i = 0; i < N; i++) cin >> a[i];
    stack<int> s;
    for (int i = 0; i < N; i++) {
        bool f = true;
        for (int j = N - 1 - i; 0 <= j; j--) {
            if (a[j] == j+1) {
                s.push(j+1);
                a.erase(a.begin()+j, a.begin()+j+1);
                f = false;
                break;
            }
        }
        if (f) {
            cout << -1 << endl;
            return 0;
        }
    }
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        cout << x << endl;
    }
}
