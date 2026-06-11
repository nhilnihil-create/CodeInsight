#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    map<int, int> A;
    int n;
    cin >> n;

    rep(i, n) {
        int tmp;
        cin >> tmp;
        tmp--;

        if (A.count(tmp)) {
            A[tmp]++;
        } else {
            A[tmp] = 1;
        }
    }

    int cnt = 0;
    for (auto a : A) {
        int x = a.first + 1;
        int y = a.second;

        if (x < y) {
            cnt += (y - x);
        } else if (x > y) {
            cnt += y;
        }
    }
    cout << cnt << endl;

    return 0;
}