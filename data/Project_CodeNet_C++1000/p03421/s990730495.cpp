#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void out(deque<int> v) {
    int sz = v.size();
    for (int i = 0; i < sz; i++) {
        cout << v.front() << " \n"[i == sz - 1];
        v.pop_front();
    }
}

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    if (a * b < n) {
        cout << -1 << endl;
        return 0;
    }
    if (a + b - 1 > n) {
        cout << -1 << endl;
        return 0;
    }
    int pos = n;
    deque<int> dq;
    for (int i = 0; i < a; i++) {
        dq.push_front(pos--);
    }
    while (--b) {
        int tmp = a;
        vector<int> v;
        while (tmp-- > 0 && pos >= b) {
            v.push_back(pos--);
        }
        for (int i = 0; i < v.size(); i++) {
            dq.push_back(v[v.size() - i - 1]);
        }
    }
    out(dq);
    return 0;
}
