#include <bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define NMAX 7003
using namespace std;
int N, Q;
string s;
pair <char, char> Que[200007];
int fall(int x) {
    if (x < 0) return -1;
    if (x >= N) return 1;
    for (int i = 0; i < Q; ++i) {
        if (s[x] == Que[i].first) {
            if (Que[i].second == 'L')
                --x;
            else ++x;
        }
        if (x < 0) return -1;
        if (x >= N) return 1;
    }
    return 0;
}
int srch(int left , int right, int type) {
    int mid, sol;
    while (left <= right) {
        mid = (left + right) / 2;
        int x = fall(mid); // -1 L 0 STAY 1 R
        if (x == 1) {
            right = mid - 1;
        }
        else if (x == -1) {
            left = mid + 1;
        }
        else {
            if (type == 1) left = mid + 1;
            else right = mid - 1;
        }
        if (type == x)
            sol = mid;
    }
    return sol;
}
int main() {
    cin >> N >> Q;
    cin >> s;
    for (int i = 0; i < Q; ++i) {
        char t, d;
        cin >> t >> d;
        Que[i] = mp(t, d);
    }
    cout << N - (srch(-1, N, -1) + 1 + N - srch(0, N, 1));
    return 0;
}
