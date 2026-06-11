#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    string s;
    cin >> s;
    if (count(all(s), '-') == 1 && s[A] == '-' && s.size() == A + B + 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}