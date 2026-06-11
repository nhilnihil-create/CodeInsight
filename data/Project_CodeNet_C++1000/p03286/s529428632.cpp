#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<int> ans;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (N != 1) {
        if (N % 2 < 0) {
            ans.push_back(N % 2 + 2);
            N /= -2;
            N += 1;
        } else {
            ans.push_back(N % 2);
            N /= -2;
        }
    }
    ans.push_back(1);

    reverse(all(ans));
    for (auto a : ans) {
        cout << a;
    }
    cout << endl;
    return 0;
}