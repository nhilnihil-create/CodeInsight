#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 100000000000000000

int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    set<int> se;
    for (int i = A; i < A + K; i++) {
        if (i >= A && i <= B)
            se.insert(i);
    }

    for (int i = B; i > B - K; i--) {
        if (i >= A && i <= B)
            se.insert(i);
    }

    for (auto s : se) {
        cout << s << endl;
    }
}