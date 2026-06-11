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
    vector<int> a(N);
    int cnt = 0;
    rep(i, N) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            cnt++;
        }
    }

    cout << cnt << endl;
}