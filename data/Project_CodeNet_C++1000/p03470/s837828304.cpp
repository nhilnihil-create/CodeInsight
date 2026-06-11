#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, d;
    cin >> N;
    set<int> s;
    rep(i, N) {
        cin >> d;
        s.insert(d);
    }
    cout << s.size() << "\n";
}